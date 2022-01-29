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


// Chaining in an elementary 10-cell hash table for integers
# include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};
class LinkedList
{ // The functions return back root as there is no Node* class member 
    public:
    Node* sortedInsert(Node*, int);
    bool search(Node*, int);
    Node* del(Node*, int);
    Node* delAll(Node*);
};
Node* LinkedList::sortedInsert(Node* root, int toIns)
{
    Node* newNode = new Node;
    if(!root)
    {
        newNode->data = toIns;
        newNode->next = NULL;
        root = newNode;
    }
    else if(toIns < root->data)
    {
        newNode->data = toIns;
        newNode->next = root;
        root = newNode;
    }
    else
    {
        Node* temp = root;
        Node* tailPtr; 
        while(temp && toIns > temp->data)
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
bool LinkedList::search(Node* root, int toFind)
{
    if(!root)
        return false;
    Node* ptr = root;
    while(ptr)
    {
        if(toFind < ptr->data)
            return false;
        else if(toFind > ptr->data)
            ptr = ptr->next;
        else
            return true;
    }
    return false; // reached the end
}
Node* LinkedList::del(Node* root, int toDel)
{
    if(root)
    {
        Node* ptr = root;
        Node* tailPtr;
        while(ptr)
        {
            if(toDel < ptr->data) // not found
                break;
            else if(toDel > ptr->data) // persist
            {
                tailPtr = ptr;
                ptr = ptr->next;
            }
            else // found
            {
                if(ptr == root)
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
Node* LinkedList::delAll(Node* root)
{
    Node* temp;
    while(root)
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
    Node** HT;
    int size;
    LinkedList l;
    int hash(int x)
    {
        return abs(x%size); // make changes as per requirements
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
        for(int i = 0; i < size; i++)
            HT[i] = l.delAll(HT[i]);
    }
};
HashTable::HashTable(int size)
{
    this->size = (size >= 10) ? size : 10;
    HT = new Node*[this->size];
    for(int i = 0; i < this->size; i++)
        HT[i] = NULL;
}

int main()
{
    HashTable h(10); // sizes greater than 10 can be passed
    int res;
    while(true)
    {
        cout << "1. Insert a number\n2. Search for a number\n";
        cout << "3. Delete a number\n4. Exit the menu\n";
        cout << "Enter your choice: "; cin >> res;
        if(res == 1)
        {
            cout << "Enter a number to insert: ";
            cin >> res; h.insert(res);
            cout << res << " was inserted successfully\n";
        }
        else if(res == 2)
        {
            cout << "Enter a key to search: "; cin >> res;
            cout << res << " was " << (h.search(res) ? "" : "not ") << "found\n";
        }
        else if(res == 3)
        {
            cout << "Enter a key to delete: "; cin >> res;
            if(h.search(res))
            {
                h.del(res);
                cout << res << " was successfully deleted\n";
            }
            else
                cout << res << " was not found in the hash table\n";
        }
        else if(res == 4)
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
