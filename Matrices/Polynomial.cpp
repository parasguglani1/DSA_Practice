//Implementing polynomials in C++
#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

class term
{
    public:
    int coeff;
    int power;
    term& operator =(term&);
};

term& term::operator =(term& t)
{
    this->coeff = t.coeff;
    this->power = t.power;
    return t;
}

class polynomial
{
    private:
    int numTerms;
    term* t;
    void resize(int);
    void putter(int);
    public:
    polynomial(int n = 0)
    {
        if(n > 0) //highest power of n
            numTerms = n;
        else
            numTerms = 1; //default - constant
        t = new term[n+1]; //max terms plausible
    }
    friend istream& operator >>(istream&, polynomial&);
    friend ostream& operator <<(ostream&, polynomial&);
    polynomial operator +(polynomial&);
    int value(int);
    ~polynomial();
};

void polynomial::resize(int val)
{
    if(val < numTerms)
    {
        term* temp = new term[val];
        for(int i = 0; i < val; i++)
            temp[i] = t[i];
        delete []t;
        t = temp;
        temp = NULL;
    }
}

istream& operator >>(istream& in, polynomial& p)
{
    //we have the memory allocated along with highest n
    int temp, currIndex = 0;
    for(int i = p.numTerms; i >= 0; i--)
    {
        cout<<"Enter the coefficient for "<<i<<"th power of x: ";
        in>>temp;
        if(temp != 0)
        {
            p.t[currIndex].coeff = temp;
            p.t[currIndex].power = i;
            currIndex++;
        }
    }
    p.resize(currIndex);
    p.numTerms = currIndex; //finally, the correct value
    return in;
}

polynomial polynomial::operator +(polynomial& q)
{
    polynomial ans(numTerms + q.numTerms); //max plausible
    int currIndex = 0;
    int i = 0, j = 0;
    while(i < numTerms && j < q.numTerms)
    {
        if(this->t[i].power > q.t[j].power)
            ans.t[currIndex++] = this->t[i++];
        else if(this->t[i].power < q.t[j].power)
            ans.t[currIndex++] = q.t[j++];
        else
        {
            ans.t[currIndex] = this->t[i++];
            ans.t[currIndex++].coeff += q.t[j++].coeff;
        }
    }
    for(; i < this->numTerms; i++)
        ans.t[currIndex++] = this->t[i];
    for(; j < q.numTerms; j++)
        ans.t[currIndex++] = q.t[j];
    ans.resize(currIndex);
    ans.numTerms = currIndex;
    return ans;
}

void polynomial::putter(int n)
{
    SetConsoleOutputCP(65001);
    string rev = "";
    while(n > 0)
    {
        rev += (char)(n%10 + 48);
        n = n/10;
    }
    while(rev.length() > 0)
    {
        n = (int)rev[rev.length() - 1] - 48;
        rev = rev.substr(0, rev.length() - 1);
        
        if(n==1)
            printf("¹");
        else if(n==2)
            printf("²");
        else if(n==3)
            printf("³");
        else if(n==4)
            printf("⁴");
        else if(n==5)
            printf("⁵");
        else if(n==6)
            printf("⁶");
        else if(n==7)
            printf("⁷");
        else if(n==8)
            printf("⁸");
        else if(n==9)
            printf("⁹");
        else
            printf("⁰");
    }
}

ostream& operator <<(ostream& out, polynomial& p)
{
    for(int i = 0; i < p.numTerms; i++)
    {
        if(p.t[i].coeff != 1)
            out<<p.t[i].coeff;
        if(p.t[i].power != 0) //writes 'x' in the output
            out<<"x";
        if(p.t[i].power != 1)
            p.putter(p.t[i].power); //prints the superscripted exponent
        if(i != p.numTerms-1 && p.t[i+1].coeff > 0)
            out<<"+"; //prints the leading addition symbol      
    }
    return out;
}

int polynomial::value(int x)
{
    int ans = 0;
    for(int i = 0; i < numTerms; i++)
        ans += t[i].coeff*pow(x, t[i].power);
    return ans;
}

polynomial::~polynomial()
{
    numTerms = 0;
    delete []t;
    cout<<"Object destructed\n";
}

void reader(int* n, string s, int cond)
{
    int var;
    while(true)
    {
        cout<<"Enter the "<<s<<": "; cin>>var;
        if(cond == 0 && var > 0 || cond == 1)
            break;
        cout<<"Invalid input, retry with a non-negative integer\n";
    }
    *n = var;
}

int main()
{
    int hPow, sol; 
    cout<<"---------Polynomial 1---------\n";
    reader(&hPow, "highest power of the polynomial", 0);
    polynomial p(hPow); cin>>p;
    
    cout<<"---------Polynomial 2---------\n";
    reader(&hPow, "highest power of the polynomial", 0);
    polynomial q(hPow); cin>>q;

    polynomial r = p + q;
    
    reader(&sol, "value of x", 1);
    cout<<"For x = "<<sol<<", the value of:\n";
    cout<<p<<" = "<<p.value(sol)<<"\n";
    cout<<q<<" = "<<q.value(sol)<<"\n";
    cout<<r<<" = "<<r.value(sol)<<"\n";

    return 0;
}