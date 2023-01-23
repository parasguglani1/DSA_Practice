// Hash table implementing collusion-resolution technique linear probing
// Only n/2 elements permittable for an n-sized hash table

/* Quadratic probing: open addressing, another collision resolution technique.
It's similar to linear probing, but there's a difference:
Linear: h'(x)=(h(x)+f(i))%size where f(i)=1, i=0,1,2...
Quadratic: h'(x)=(h(x)+f(i))%size where f(i)=i^2, i=0,1,2...
This means that elements are stored farther and farther away each time a collision
occurs at a given place.
Analysis:
Avg. successful search: (-log base e(1 - lambda))/lambda
Avg. unsuccessful search: 1/(1 - lambda)
*/
#include <iostream>
using namespace std;

class QuadProbHash
{
private:
    int *arr;
    int size;
    int filled;
    int hash(int ele)
    {
        return ele % size;
    }
    int linProb(int);
    bool search(int, int *);

public:
    QuadProbHash(int);
    void insert(int);
    int search(int);
    friend ostream &operator<<(ostream &, QuadProbHash &);
    ~QuadProbHash()
    {
        delete arr;
    }
};
int QuadProbHash::linProb(int ele)
{
    int index = hash(ele), i = 0;
    while (*(arr + (index + i * i) % size) != 0)
    {
        i++;
    }
    return (index + i * i) % size;
}
bool QuadProbHash::search(int ele, int *ind)
{
    *ind = hash(ele);
    int i = 0;
    while (*(arr + (*ind + i * i) % size) != 0)
    {
        if (arr[(*ind + i * i) % size] == ele)
        {
            *ind = (*ind + i * i) % size;
            return true;
        }
        i++;
    }
    return false;
}
QuadProbHash::QuadProbHash(int x)
{
    size = (x > 0) ? x : 10;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
    filled = 0;
}
void QuadProbHash::insert(int ele)
{
    if (filled >= size / 2 || ele < 0)
        return;
    int index = linProb(ele);
    *(arr + index) = ele;
    filled++;
}
int QuadProbHash::search(int ele)
{
    int index;
    if (search(ele, &index))
        return index;
    else
        return -1;
}

ostream &operator<<(ostream &out, QuadProbHash &l)
{
    for (int i = 0; i < l.size; i++)
        if (l.arr[i] != 0)
            out << i << " " << l.arr[i] << "\n";
    return out;
}

int main()
{
    QuadProbHash h(10);
    h.insert(11);  // at index 1
    h.insert(55);  // at index 5
    h.insert(211); // at index 2
    h.insert(1);   // at index (1+3*3)%10 (since index 5 has 55)
    h.insert(199); // at index 9
    h.insert(231); // won't be inserted to prevent loading factor from exceeding 0.5
    cout << "Displaying hash table:\n"
         << h;
    cout << "1 was found at index: " << h.search(1) << "\n";
    cout << "135 was found at index: " << h.search(135) << "\n";
    return 0;
}