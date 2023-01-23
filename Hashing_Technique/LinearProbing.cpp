// Hash table implementing collusion-resolution technique linear probing
// Only n/2 elements permittable for an n-sized hash table
/* Linear probing: a form of closed hashing, since it will not consume extra space
besides the space available in the hash table, instead it searches for the next free
space to store an element that has collided with another one where it was mapped.
It's based on the hash function: h'(x)=(h(x)+f(i))%size where f(i)=1, i=0,1,2...
The same as using h(x)=x%size and looking for the next free space when there's a collision.

Analysis: it takes more than constant time. The loading factor (lambda = n/size) should
always be <= 0.5, this means that inside an array of size 10, there should be only 5 keys.
Time taken:
Avg. successful search: t = 1 / lambda * natural log(1 / 1-lambda)
Avg. unsuccessful search: t = 1 / 1-lambda

Drawbacks: must keep half of the hash table vacant (waste of space); different keys together
may form a cluster (primary clustering of keys); when deleting keys, a place is left vacant,
if nothing is done with the next keys (that could occupy the space), when searching for a key
that is after the extra space, this would lead to an unsuccessful search since the search stops
after finding a blank space. Since rearranging the keys isn't simple, one solution is called
"rehashing", taking all the keys and inserting them into the hash table once again. Considering
the amount of work, in linear probing we avoid deleting keys, instead, we could put a flag (1 or 0)
to show if the key is there or not (when it should have been deleted).
*/
#include <iostream>
using namespace std;

class LinProbHash
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
    LinProbHash(int);
    void insert(int);
    int search(int);
    friend ostream &operator<<(ostream &, LinProbHash &);
    ~LinProbHash()
    {
        delete arr;
    }
};
int LinProbHash::linProb(int ele)
{
    int index = hash(ele), i = 0;
    while (*(arr + index + i) != 0)
    {
        i = (i + 1) % size;
    }
    return (index + i) % size;
}
bool LinProbHash::search(int ele, int *ind)
{
    *ind = hash(ele);
    while (*(arr + *ind) != 0)
    {
        if (arr[*ind] == ele)
            return true;
        *ind = (*ind + 1) % size;
    }
    return false;
}
LinProbHash::LinProbHash(int x)
{
    size = (x > 0) ? x : 10;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
    filled = 0;
}
void LinProbHash::insert(int ele)
{
    if (filled >= size / 2 || ele < 0)
        return;
    int index = linProb(ele);
    *(arr + index) = ele;
    filled++;
}
int LinProbHash::search(int ele)
{
    int index;
    if (search(ele, &index))
        return index;
    else
        return -1;
}

ostream &operator<<(ostream &out, LinProbHash &l)
{
    for (int i = 0; i < l.size; i++)
        if (l.arr[i] != 0)
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
    cout << "Displaying hash table:\n"
         << h;
    cout << "211 was found at index: " << h.search(211) << "\n";
    cout << "135 was found at index: " << h.search(135) << "\n";
    return 0;
}