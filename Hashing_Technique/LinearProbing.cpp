// Hash table implementing collusion-resolution technique linear probing
// Only n/2 elements permittable for an n-sized hash table
# include <iostream>
using namespace std;

class LinProbHash
{
    private:
    int* arr;
    int size;
    int filled;
    int hash(int ele)
    {
        return ele%size;
    }
    int linProb(int);
    bool search(int, int*);
    public:
    LinProbHash(int);
    void insert(int);
    int search(int);
    friend ostream& operator <<(ostream&, LinProbHash&);
    ~LinProbHash()
    {
        delete arr;
    }
};
int LinProbHash::linProb(int ele)
{
    int index = hash(ele), i = 0;
    while(*(arr + index + i) != 0)
    {
        i = (i + 1) % size;
    }
    return (index + i) % size;
}
bool LinProbHash::search(int ele, int* ind)
{
    *ind= hash(ele);
    while(*(arr + *ind) != 0)
    {
        if(arr[*ind] == ele)
            return true;
        *ind = (*ind + 1) % size;
    }
    return false;
}
LinProbHash::LinProbHash(int x)
{
    size = (x > 0) ? x : 10;
    arr = new int[size];
    for(int i = 0; i < size; i++)
        arr[i] = 0;
    filled = 0;
}
void LinProbHash::insert(int ele)
{
    if(filled >= size/2 || ele < 0)
        return;
    int index = linProb(ele);
    *(arr+index) = ele;
    filled++;
}
int LinProbHash::search(int ele)
{
    int index;
    if(search(ele, &index))
        return index;
    else
        return -1;
}

ostream& operator <<(ostream& out, LinProbHash& l)
{
    for(int i = 0; i < l.size; i++)
        if(l.arr[i] != 0)
            out << i << " " << l.arr[i] << "\n";
    return out;
}

int main()
{
    LinProbHash h(10);
    h.insert(11);
    h.insert(55);
    h.insert(211);
    h.insert(1);
    h.insert(199);
    h.insert(231);
    cout << "Displaying hash table:\n" << h;
    cout << "211 was found at index: " << h.search(211) << "\n";
    cout << "135 was found at index: " << h.search(135) << "\n";
    return 0;
}