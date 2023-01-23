/* Type of a searching technique, which is used to search an element in almost constant time

Linear Search -> O(N)
Binary Search -> O(log N)

in hashing a global array hsh[N] is declared.
you know about this method thru luv

Drawback: Space difficulty(a lot of space is required)

Hash Table: Keys are mapped on hash table

Mapping:
1. one-one -> function
2. many-one
3. many-one -> function
4. many-many

hash function: hsh(x) = x
modify hash function

hsh(x) = x % 10;

sometimes COLLISION occurs, when we need to store two values at same location, after applying modulus,
so to solve this problem we have two mathods:

1. Open hashing
2. Closed Hashing */

/* Hashing is mainly used for searching.
Advantages:
Compared to linear search, which is O(n), and binary search, which is O(log n),
hashing has a better time complexity since it could be O(1) depending on the technique.
For example, going to an index that is the same as the key you're looking for:
key: 18, then go to A[18].
Drawbacks:
Suppose the only values being stored are 3, 5, 18, this means that an array of size 19
would be needed even if occupied by three elements only, each at the index of the same number.
This is why hashing techniques exist.

Relational mappings:
one to one (function)
one to many (not a function)
many to one (function)
many to many (not a function)

We'll use functions for mapping:
One to one (ideal hashing, O(1)):
Each key go to its corresponding index, e.g: 4 goes to A[4].
That is: h(x) = x
Drawback: too much space required. Option: many to one.

Many to one:
Modulus hash function, e.g: h(x) = x % 10
Drawback: Collision, two keys could be mapped at the same index, for example,
15 and 25 would both go to A[5], since 15%10 = 5 and 25%10 = 5.
Solution: Open Hashing and Closed Hashing (Open Addressing by 1.linear probing or
2.quadratic probing or 3.double hashing). */

/* Chaining:
A hash table made of an array of linked lists, each index being a pointer to a sorted LL.
Analysis: always done considering the loading factor, not the number of elements like other DS.
Take: n elements in an array of some size, suppose n = 100 and size = 100.
Loading factor: lambda = n/size, in the example: 100/10 = 10, the loading factor is 10.
It means that at each location there are approx. 10 keys.
Avg. successful search time:  t = 1 + lambda/2, it means: 1 for the hash function + the avg. number
of elements inside a linked list.
Avg. unsuccessful search time: t = 1 + lambda
Deleting: similar to deleting a node from a LL, first search then when it's found, delete it.

It's possible to modify the hash function. h(x) = x % 10 takes the last digit into consideration.
To take the second-to-last digit: h(x) = (x%10)%10
It's important to select a hash function such that the keys are uniformly distributed. You must have
an idea about the keys you're going to work with in order to choose the appropriate hash function.

*/

// Chaining in an elementary 10-cell hash table for integers
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{ // The functions return back root as there is no Node* class member
public:
    Node *sortedInsert(Node *, int);
    bool search(Node *, int);
    Node *del(Node *, int);
    Node *delAll(Node *);
};
Node *LinkedList::sortedInsert(Node *root, int toIns)
{
    Node *newNode = new Node;
    if (!root)
    {
        newNode->data = toIns;
        newNode->next = NULL;
        root = newNode;
    }
    else if (toIns < root->data)
    {
        newNode->data = toIns;
        newNode->next = root;
        root = newNode;
    }
    else
    {
        Node *temp = root;
        Node *tailPtr;
        while (temp && toIns > temp->data)
        {
            tailPtr = temp;
            temp = temp->next;
        }
        newNode->data = toIns;
        newNode->next = tailPtr->next;
        tailPtr->next = newNode;
    }
    return root;
}
bool LinkedList::search(Node *root, int toFind)
{
    if (!root)
        return false;
    Node *ptr = root;
    while (ptr)
    {
        if (toFind < ptr->data)
            return false;
        else if (toFind > ptr->data)
            ptr = ptr->next;
        else
            return true;
    }
    return false; // reached the end
}
Node *LinkedList::del(Node *root, int toDel)
{
    if (root)
    {
        Node *ptr = root;
        Node *tailPtr;
        while (ptr)
        {
            if (toDel < ptr->data) // not found
                break;
            else if (toDel > ptr->data) // persist
            {
                tailPtr = ptr;
                ptr = ptr->next;
            }
            else // found
            {
                if (ptr == root)
                    root = NULL;
                else
                    tailPtr->next = ptr->next;
                delete ptr;
                break;
            }
        }
        // reached the list end
    }
    return root;
}
Node *LinkedList::delAll(Node *root)
{
    Node *temp;
    while (root)
    {
        temp = root;
        root = root->next;
        delete temp;
    }
    return root;
}

class HashTable
{
private:
    Node **HT;
    int size;
    LinkedList l;
    int hash(int x)
    {
        return abs(x % size); // make changes as per requirements
    }
    int abs(int x)
    {
        return (x >= 0) ? x : -x;
    }

public:
    HashTable(int);
    void insert(int ele)
    {
        int index = hash(ele);
        HT[index] = l.sortedInsert(HT[index], ele);
    }
    bool search(int ele)
    {
        int index = hash(ele);
        return l.search(HT[index], ele);
    }
    void del(int ele)
    {
        int index = hash(ele);
        HT[index] = l.del(HT[index], ele);
    }
    ~HashTable()
    {
        for (int i = 0; i < size; i++)
            HT[i] = l.delAll(HT[i]);
    }
};
HashTable::HashTable(int size)
{
    this->size = (size >= 10) ? size : 10;
    HT = new Node *[this->size];
    for (int i = 0; i < this->size; i++)
        HT[i] = NULL;
}

int main()
{
    HashTable h(10); // sizes greater than 10 can be passed
    int res;
    while (true)
    {
        cout << "1. Insert a number\n2. Search for a number\n";
        cout << "3. Delete a number\n4. Exit the menu\n";
        cout << "Enter your choice: ";
        cin >> res;
        if (res == 1)
        {
            cout << "Enter a number to insert: ";
            cin >> res;
            h.insert(res);
            cout << res << " was inserted successfully\n";
        }
        else if (res == 2)
        {
            cout << "Enter a key to search: ";
            cin >> res;
            cout << res << " was " << (h.search(res) ? "" : "not ") << "found\n";
        }
        else if (res == 3)
        {
            cout << "Enter a key to delete: ";
            cin >> res;
            if (h.search(res))
            {
                h.del(res);
                cout << res << " was successfully deleted\n";
            }
            else
                cout << res << " was not found in the hash table\n";
        }
        else if (res == 4)
        {
            cout << "Menu exited\n";
            break;
        }
        else
            cout << "Retry with a valid input\n";
        cout << "--------------------------------\n";
    }
    return 0;
}
