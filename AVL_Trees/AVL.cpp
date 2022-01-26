// Implementing Adelson-Velsky Landis Tree with insertion, deleteion, search and display utilities
#include <iostream>
#include <queue>
using namespace std;
/* AVL Trees: highly balanced binary search trees.
Balance factor: height of left subtree - height of right subtree: bf = hl - hr = {-1, 0, 1}
bf = | hl - hr | <= 1, if: bf = | hl - hr | > 1, it's unbalanced. It's calculated for every
node in the tree. Balancing is performed by rotations.
Rotations: always done on three nodes, starting from the topmost that became unbalanced and
going two nodes down.
Single rotations:
LL-Rotation/Clock-wise rotation when the tree is unbalanced with too many nodes on the left.
RR-Rotation/Counterclockwise rotation "    "     "     "     "     "      "     "    right.
Double (two-step) rotations:
LR-Rotation: when there are many nodes on the left with some going to the right.
Firstly, a left rotation is performed, then, a right one
RL-Rotation: when there are many nodes on the right with some going to the left.
Firstly, a right rotation is performed, then, a left one

*/

class AVLNode
{
    public:
    int data;
    int lev;
    AVLNode* left;
    AVLNode* right;
    void __init__(int x)
    {
        data = x;
        lev = 1;
        left = right = NULL;
    }
};

class AVL
{
    AVLNode* root;
    int lev(AVLNode* ptr); // Node-level returned arithmetically
    int balfac(AVLNode* ptr); // balancng factor returned arithmetically
    AVLNode* LLRot(AVLNode* ptr); // LL Rotation
    AVLNode* RRRot(AVLNode* ptr); // RR Rotation
    AVLNode* LRRot(AVLNode* ptr); // LR Rotation
    AVLNode* RLRot(AVLNode* ptr); // RL Rotation
    AVLNode* insert(AVLNode* ptr, int x); // recursively inserts while keeping the tree balanced
    void inOrder(AVLNode* ptr); // displays tree by traversing it in-order
    AVLNode* search(AVLNode* ptr, int key); // identical to binary search tree's
    AVLNode* predecessor(AVLNode* ptr); // finds predecessor in left sub-tree, to the current node (to be deleted)
    AVLNode* successor(AVLNode* ptr); // finds successor in right sub-tree, to the current node (to be deleted)
    AVLNode* del(AVLNode* ptr, int key); // recursively deletes whilst keep the tree balanced
    public:
    AVL(){root = NULL;}
    void insert(int x); // caller to insert(AVLAVLNode*, int)
    void inOrder(); // caller to inOrder(AVLAVLNode*)
    void levelOrder(); // displays tree by traversing it by level, using a queue
    bool search(int x); // caller to search(AVLAVLNode*, int)
    void del(int x); // caller to del(AVLAVLNode*, int)
    bool isEmpty(); // to check if the tree is empty
    ~AVL(); // destructor, uses queue
};

int AVL::lev(AVLNode* ptr)
{
    int hl = ptr && ptr->left ? ptr->left->lev : 0;
    int hr = ptr && ptr->right ? ptr->right->lev : 0;
    return hl > hr ? hl+1 : hr+1;
}
int AVL::balfac(AVLNode* ptr)
{
    int hl = ptr && ptr->left ? ptr->left->lev : 0;
    int hr = ptr && ptr->right ? ptr->right->lev : 0;
    return hl - hr;
}
AVLNode* AVL::LLRot(AVLNode* ptr)
{
    AVLNode* ptrL = ptr->left;
    AVLNode* ptrLR = ptr->left->right;
    
    ptr->left = ptrLR;
    ptrL->right = ptr;
    
    ptr->lev = lev(ptr);
    ptrL->lev = lev(ptrL);
    
    if(ptr == root)
        root = ptrL;
    
    return ptrL;
}
AVLNode* AVL::RRRot(AVLNode* ptr)
{
    AVLNode* ptrR = ptr->right;
    AVLNode* ptrRL = ptr->right->left;
    
    ptr->right = ptrRL;
    ptrR->left = ptr;
    
    ptr->lev = lev(ptr);
    ptrR->lev = lev(ptrR);
    
    if(ptr == root)
        root = ptrR;
    
    return ptrR;
}
AVLNode* AVL::LRRot(AVLNode* ptr)
{
    AVLNode* ptrL = ptr->left;
    AVLNode* ptrLR = ptr->left->right;
    
    ptrL->right = ptrLR->left;
    ptr->left = ptrLR->right;
    ptrLR->left = ptrL;
    ptrLR->right = ptr;
    
    ptr->lev = lev(ptr);
    ptrL->lev = lev(ptrL);
    ptrLR->lev = lev(ptrLR);
    
    if(ptr == root)
        root = ptrLR;
    
    return ptrLR;
}
AVLNode* AVL::RLRot(AVLNode* ptr)
{
    AVLNode* ptrR = ptr->right;
    AVLNode* ptrRL = ptr->right->left;
    
    ptrR->left = ptrRL->right;
    ptr->right = ptrRL->left;
    ptrRL->right = ptrR;
    ptrRL->left = ptr;
    
    ptr->lev = lev(ptr);
    ptrR->lev = lev(ptrR);
    ptrRL->lev = lev(ptrRL);
    
    if(ptr == root)
        root = ptrRL;
    
    return ptrRL;
}
AVLNode* AVL::insert(AVLNode* ptr, int x)
{
    if(!ptr)
    {
        ptr = new AVLNode;
        ptr->__init__(x);
        return ptr;
    }
    if(x < ptr->data)
        ptr->left = insert(ptr->left, x);
    else if(x > ptr->data)
        ptr->right = insert(ptr->right, x);
    
    ptr->lev = lev(ptr);
    int bf = balfac(ptr), bfl = balfac(ptr->left), bfr = balfac(ptr->right);
    
    if(bf == 2 and bfl == 1)
        ptr = LLRot(ptr);
    else if(bf == 2 and bfl == -1)
        ptr = LRRot(ptr);
    else if(bf == -2 and bfr == -1)
        ptr = RRRot(ptr);
    else if(bf == -2 and bfr == 1)
        ptr = RLRot(ptr);
    
    return ptr;
}
void AVL::inOrder(AVLNode* ptr)
{
    if(ptr)
    {
        inOrder(ptr->left);
        cout << ptr->data << " ";
        inOrder(ptr->right);
    }
}
AVLNode* AVL::search(AVLNode* ptr, int key)
{
    if(!ptr)
        return NULL;
    if(key < ptr->data)
        return search(ptr->left, key);
    else if(key > ptr->data)
        return search(ptr->right, key);
    return ptr;
}
AVLNode* AVL::predecessor(AVLNode* ptr)
{
    while(ptr && ptr->right)
        ptr = ptr->right;
    return ptr;
}
AVLNode* AVL::successor(AVLNode* ptr)
{
    while(ptr && ptr->left)
        ptr = ptr->left;
    return ptr;
}
AVLNode* AVL::del(AVLNode* ptr, int key)
{
    if(!ptr)
        return NULL;
    if(ptr->data == key and !ptr->left and !ptr->right)
    {
        delete ptr;
        return NULL;
    }
    if(key < ptr->data)
        ptr->left = del(ptr->left, key);
    else if(key > ptr->data)
        ptr->right = del(ptr->right, key);
    else
    {
        if(lev(ptr->left) > lev(ptr->right))
        {
            AVLNode* q = predecessor(ptr->left);
            ptr->data = q->data;
            ptr->left = del(ptr->left, q->data);
        }
        else
        {
            AVLNode* q = successor(ptr->right);
            ptr->data = q->data;
            ptr->right = del(ptr->right, q->data);
        }
    }
    
    ptr->lev = lev(ptr);
    int bf = balfac(ptr), bfl = balfac(ptr->left), bfr = balfac(ptr->right);
    if(bf == 2 and bfl == 1)
        ptr = LLRot(ptr);
    else if(bf == 2 and (bfl == -1 or bfl == 0))
        ptr = LRRot(ptr);
    else if(bf == -2 and bfr == -1)
        ptr = RRRot(ptr);
    else if(bf == -2 and (bfr == 1 or bfr == 0))
        ptr = RLRot(ptr);
    
    return ptr;
}

void AVL::insert(int x)
{
    root = insert(root, x);
}
void AVL::inOrder()
{
    cout << "In-order traversal: ";
    inOrder(root);
    cout << "\n";
}
void AVL::levelOrder()
{
    queue<AVLNode*> que; que.push(root);
    AVLNode* temp;
    cout << "Level order traversal: ";
    while(!que.empty())
    {
        temp = que.front(); que.pop();
        if(temp->left)
            que.push(temp->left);
        if(temp->right)
            que.push(temp->right);
        cout << temp->data << " ";
    }
    cout << "\n";
}
bool AVL::search(int x)
{
    return search(root, x) ? true : false;
}
void AVL::del(int x)
{
    root = del(root, x);
}
bool AVL::isEmpty()
{
    return root == NULL;
}
AVL::~AVL()
{
    queue<AVLNode*> que; que.push(root);
    AVLNode* temp;
    while(!que.empty())
    {
        temp = que.front(); que.pop();
        if(temp->left)
            que.push(temp->left);
        if(temp->right)
            que.push(temp->right);
        delete temp;
    }
    cout << "Adelson-Velsky Landis Tree destructed\n";
}

int main()
{
    AVL a;
    cout << "Adelson-Velsky Landis Tree:\n";
    while(true)
    {
        cout<<"1. Insert an element into the tree\n2. Delete an element from the tree\n";
        cout<<"3. Search for an element in the tree\n4. Display the tree\n0. Exit menu\n";
        cout << "Enter your choice: "; int choice; cin>>choice;
        if(!choice)
        {
            cout << "Menu exited\n";
            break;
        }
        else if(choice == 1)
        {
            cout<<"Enter the number to be inserted: ";
            int num; cin>>num; a.insert(num);
            cout<<num<<" was successfully inserted\n";
        }
        else if(choice == 2)
        {
            if(a.isEmpty())
                cout<<"Tree is empty, please insert element(s) first\n";
            else
            {
                cout<<"Enter the number to be deleted: ";
                int num; cin>>num;
                if(a.search(num))
                {
                    a.del(num);
                    cout<<num<<" was successfully deleted\n";
                }
                else
                    cout<<num<<" cannot be deleted since it is not in the tree\n";
            }
        }
        else if(choice == 3)
        {
            if(a.isEmpty())
                cout<<"Tree is empty, please insert element(s) first\n";
            else
            {
                cout<<"Enter the number to be searched: ";
                int num; cin>>num;
                cout<< num << " was " << (a.search(num) ? "" : "not ") << "found in the tree\n";
            }
        }
        else if(choice == 4)
        {
            if(a.isEmpty())
                cout<<"Tree is empty, please insert element(s) first\n";
            else
            {
                char c;
                while(true)
                {
                    cout<<"Display [I]n-order or [L]evel-order: "; cin>>c;
                    if(c == 'I' || c == 'i' || c == 'L' || c == 'l')
                        break;
                    else
                        cout<<"Invalid choice, try again\n";
                }
                (c == 'I' or c == 'i') ? a.inOrder() : a.levelOrder();
            }
        }
        else
            cout<<"Invalid choice, try again\n";
        cout << "-------------------------------------\n";
    }
    return 0;
}