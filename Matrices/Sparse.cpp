
#include <iostream>
using namespace std;

class Element
{
    public:
    int row;
    int col;
    int val; //data type of the matrix
    Element& operator =(Element&);
};

Element& Element::operator =(Element& e)
{
    this->row = e.row;
    this->col = e.col;
    this->val = e.val;
    return *this;
}
static int UID = 0;
class Sparse
{
    private:
    int numRows;
    int numCols;
    int numNon0s;
    int unID;
    Element* arr; //pointer to heap
    public:
    Sparse(int a, int b)
    {
        if(a > 0 && b > 0 && a != INT_MIN && b != INT_MIN)
        {
            numRows = a;
            numCols = b;
            arr = new Element[numRows*numCols]; //worst-case - no zeroes
        }
        else
        {
            cout<<"Faulty input led to assignment of default dimensions\n";
            numRows = numCols = 2; //default
        }
        numNon0s = 0;
        unID = ++UID;
    }
    void allocator(int);
    friend istream& operator >>(istream&, Sparse&);
    friend ostream& operator <<(ostream&, Sparse&);
    Sparse operator +(Sparse&);
    ~Sparse();
    int getRows(){return numRows;}
    int getCols(){return numCols;}
};

void Sparse::allocator(int mag)
{
    if(mag == -1)
    {
        Element* t = new Element[numNon0s];
        for(int i = 0; i < numNon0s; i++)
            t[i] = arr[i];
        delete []arr;
        arr = t;
        t = NULL;
    } //preventing wastage
    else if(mag > 0)
        arr = new Element[mag];
}

istream& operator >>(istream& in, Sparse& sp)
{
    //illusion of 2D array
    //cout<<"Enter the matrix elements:\n";
    int temp;
    for(int i = 0; i < sp.numRows; i++)
    {
        for(int j = 0; j < sp.numCols; j++)
        {
            in>>temp;
            if(temp != 0)
            {
                sp.arr[sp.numNon0s].col = j;
                sp.arr[sp.numNon0s].row = i;
                sp.arr[sp.numNon0s].val = temp;
                sp.numNon0s++;
            }
        }
    }
    sp.allocator(-1);
    return in;
}

ostream& operator <<(ostream& out, Sparse& sp)
{
    int i, j, tracker = 0;
    out<<"The matrix is:\n";
    for(i = 0; i < sp.numRows; i++)
    {
        for(j = 0; j < sp.numCols; j++)
        {
            if(i == sp.arr[tracker].row && j == sp.arr[tracker].col)
                out<<sp.arr[tracker++].val<<" ";
            else
                out<<"0 ";
        }
        out<<"\n";
    }
    return out;
}

Sparse::~Sparse()
{
    numRows = numCols = numNon0s = 0;
    delete []arr;
    cout<<"Deleted object: "<<unID<<"\n";
}

Sparse Sparse::operator +(Sparse& b)
{
    if(this->numRows == b.numRows && this->numCols == b.numCols)
    {
        Sparse* c = new Sparse(numRows, numCols);
        c->allocator(this->numNon0s+b.numNon0s);

        int i = 0, j = 0; 
        while(i < this->numNon0s && j < b.numNon0s)
        {
            if(this->arr[i].row < b.arr[j].row)
                c->arr[c->numNon0s++] = this->arr[i++]; //sets c->arr[ind]'s row, col and val equal to the RHS's
            else if(this->arr[i].row > b.arr[j].row)
                c->arr[c->numNon0s++] = b.arr[j++];
            else //both non-zero elements have the same row 
            {
                if(this->arr[i].col < b.arr[j].col)
                    c->arr[c->numNon0s++] = this->arr[i++];
                else if(this->arr[i].col > b.arr[j].col)
                    c->arr[c->numNon0s++] = b.arr[j++];
                else //both row and column of the non-zero elements are same
                {
                    c->arr[c->numNon0s] = this->arr[i++];
                    c->arr[c->numNon0s++].val += b.arr[j++].val;
                }
            }
        }

        //for remaining elements
        for(; i < this->numNon0s; i++)
            c->arr[c->numNon0s++] = this->arr[i];
        for(; j < b.numNon0s; j++)
            c->arr[c->numNon0s++] = b.arr[j];
        
        c->allocator(-1);
        //returning the answer
        return *c;
    }
    else
    {
        cout<<"The two sparse matrices are not compatible for addition\n";
        return Sparse(INT_MIN, INT_MIN);
    }
} 

void reader(int* n, string comp)
{
    int inp;
    while(true)
    {
        cout<<"Enter the number of "<<comp<<": ";
        cin>>inp;
        if(inp > 0)
            break;
        cout<<"Invalid input, try again\n";
    }
    *n = inp;
}

int main()
{
    int r, c; 
    cout<<"--------Matrix 1--------\n";
    reader(&r, "rows");
    reader(&c, "columns");
    cout<<"Enter the matrix:\n";
    Sparse S1(r, c);
    cin>>S1;
    
    cout<<"--------Matrix 2--------\n";
    reader(&r, "rows");
    reader(&c, "columns");
    cout<<"Enter the matrix:\n";
    Sparse S2(r, c);
    cin>>S2;
    
    cout<<"--------Matrix 1--------\n"<<S1;
    cout<<"--------Matrix 2--------\n"<<S2;
    cout<<"--------Adduct--------\n";
    
    if(S1.getRows() == S2.getRows() && S1.getCols() == S2.getCols())
    {
        Sparse S3 = S1+S2;
        cout<<S3;
    }
    else
        cout<<"The two sparse matrices are not compatible for addition\n";

    cout<<"Program terminated\n";
    return 0;
    //No need to call destructors unless we have dynamic objects
}
