/* Binary Search Tree:
Requirements: 1. No duplicates, 2. Inorder gives sorted order, 3. Number of BST for 'n' nodes:
T(n) = (2n Cn)/n+1, note that for each shape numbers can be filled in only one way to get the
same in-order.
Search: a pointer will look for a key while comparing if it's greater or lower than the current
node's key.
Time taken: O(H), since it depends on the height of the tree, remember: log n <= H <= n
Successful search: O(log n) || Unsuccessful search: O(n) */

/*
Binary Search Tree with following utilities:
1. Insertion - iterative as well as recursive implementations
Insert takes O(n) time, search takes O(log n): n x log n -> O(n log n)
2. Search - iterative as well as recursive implementations
3. Deletion - recursive implementation, utilizes height(BinNode*), predecessor(BinNode*) and successor(BinNode*)

Deleting: basically consists of 1. searching and 2. deleting.
Deletion occurs differently depending on: key is a leaf node, key has a single child,
key has two children, etc.
For example, if we want to delete the root node, instead of altering the rest of the
entire tree, we could substitute it by either its inorder predecessor or successor that are leaves.
Inorder predecessor: RIGHTmost child of the subtree on the LEFT.
Inorder successor: LEFTmost child of the subtree on the RIGHT.
You can choose either one randomly or base the choice on the height of the subtree, for example.
However, even using this strategy may result in making other modifications on the tree, in case
the inorder successor/predecessor has a child or not.
Time taken: depends on the height, O(log n);
subsequent modifications also depend on the height: max. O(log n)

4. Initialization - using an array with a BST in preOrder/postOrder
*/
#include "Stacks.h" // for pre-order and post-order initializations
#include "Queue.h"  // for deleting the binary search tree object
#include <bits/stdc++.h>
using namespace std;

class BinNode
{
public:
    int data;
    BinNode *left;
    BinNode *right;
    void newNode(int num)
    {
        data = num;
        left = right = NULL;
    }
};

class BinarySearchTree
{
    BinNode *root;
    void inOrder(BinNode *);          // inorder traversal and node-wise display
    BinNode *rInsert(BinNode *, int); // recursively inserts new node
    BinNode *rSearch(BinNode *, int); // recursively looks for key
    void createFromPre(int *, int);   // create tree from preorder
    void createFromPost(int *, int);  // create tree from postorder
    /*Deletion criteria*/
    int height(BinNode *);
    int numNodes(BinNode *);
    /*Previous and Next InOrder element*/
    BinNode *predecessor(BinNode *);
    BinNode *successor(BinNode *);
    // Delete element
    BinNode *deleteEle(BinNode *, int);

public:
    BinarySearchTree()
    {
        root = NULL;
    }
    BinarySearchTree(int *, int, int);
    void insert(int);      // inserts new node
    void inOrder();        // helper
    void rInsert(int);     // helper
    BinNode *search(int);  // returns key address
    BinNode *rSearch(int); // helper
    void deleteEle(int);   // helper
    ~BinarySearchTree();
};

void BinarySearchTree::insert(int toInsert)
{
    BinNode *ptr = root, *tail;
    while (ptr)
    {
        tail = ptr;
        if (toInsert < ptr->data)
            ptr = ptr->left;
        else if (toInsert > ptr->data)
            ptr = ptr->right;
        else
            return; // toInsert is already a part of the tree
    }
    ptr = new BinNode;
    ptr->newNode(toInsert);
    if (!root)
        root = ptr;
    else
    {
        if (ptr->data < tail->data)
            tail->left = ptr;
        else
            tail->right = ptr;
    }
}

void BinarySearchTree::inOrder()
{
    cout << "Tree's inorder traversal: ";
    inOrder(root);
    cout << "\n";
}

void BinarySearchTree::inOrder(BinNode *ptr)
{
    if (ptr)
    {
        inOrder(ptr->left);
        cout << ptr->data << " ";
        inOrder(ptr->right);
    }
}

void BinarySearchTree::rInsert(int toInsert)
{
    root = rInsert(root, toInsert);
}

BinNode *BinarySearchTree::rInsert(BinNode *ptr, int toInsert)
{
    if (!ptr)
    {
        ptr = new BinNode;
        ptr->newNode(toInsert);
        return ptr;
    }
    if (toInsert < ptr->data)
        ptr->left = rInsert(ptr->left, toInsert);
    else if (toInsert > ptr->data)
        ptr->right = rInsert(ptr->right, toInsert);
    return ptr;
}

BinNode *BinarySearchTree::search(int key)
{
    BinNode *ptr = root;
    while (ptr)
    {
        if (key == ptr->data)
            break;
        else if (key < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return ptr;
}

BinNode *BinarySearchTree::rSearch(int key)
{
    return rSearch(root, key);
}

BinNode *BinarySearchTree::rSearch(BinNode *ptr, int key)
{
    if (!ptr || ptr->data == key)
        return ptr;
    else if (key < ptr->data)
        return rSearch(ptr->left, key);
    else
        return rSearch(ptr->right, key);
}

int BinarySearchTree::height(BinNode *ptr)
{
    if (!ptr)
        return 0;
    int x = height(ptr->left);
    int y = height(ptr->right);
    return (x > y) ? x + 1 : y + 1;
}

int BinarySearchTree::numNodes(BinNode *ptr)
{
    if (!ptr)
        return 0;
    return numNodes(ptr->left) + numNodes(ptr->right) + 1;
}

BinNode *BinarySearchTree::predecessor(BinNode *ptr)
{
    while (ptr && ptr->right)
        ptr = ptr->right;
    return ptr;
}

BinNode *BinarySearchTree::successor(BinNode *ptr)
{
    while (ptr && ptr->left)
        ptr = ptr->left;
    return ptr;
}

BinNode *BinarySearchTree::deleteEle(BinNode *ptr, int key)
{
    if (!ptr) // not found
        return NULL;
    /*---physical deletion of a leaf node---*/
    if (ptr && ptr->data == key && !ptr->left && !ptr->right) // first condition is redundant
    {
        if (!root->left && !root->right)
            root = NULL; // if there's only root node
        delete ptr;
        return NULL;
    }
    /*Deletion algorithm*/
    // Search for the element to be deleted
    if (key < ptr->data)
        ptr->left = deleteEle(ptr->left, key);
    else if (key > ptr->data)
        ptr->right = deleteEle(ptr->right, key);
    else
    { // found
        BinNode *q = NULL;
        // Using height as deletion criteria
        if (height(ptr->left) > height(ptr->right))
        {
            /*finding element previous to the one
            to be deleted (in inOrder), in left subtree*/
            q = predecessor(ptr->left);
            ptr->data = q->data;                       // deleted node effectively replaced
            ptr->left = deleteEle(ptr->left, q->data); // go and delete the node from which we copied
        }
        else
        {
            /*finding element next to the one
            to be deleted (in inOrder), in right subtree*/
            q = successor(ptr->right);
            ptr->data = q->data;
            ptr->right = deleteEle(ptr->right, q->data);
        }
    }
    return ptr; // redundant, just like rInsert (had no explicit task)
}

void BinarySearchTree::deleteEle(int key)
{
    root = deleteEle(root, key);
}

BinarySearchTree::BinarySearchTree(int *arr, int n, int flag) : BinarySearchTree()
{
    if (flag == 0)
        createFromPre(arr, n);
    if (flag == 1)
        createFromPost(arr, n);
    else
        cout << "Invalid argument passed\n";
}

void BinarySearchTree::createFromPre(int *preOrd, int n)
{
    if (root)
        return;
    root = new BinNode;
    root->newNode(preOrd[0]);

    BinNode *newNode, *ptr = root;
    Stack<BinNode *> stk;
    int i = 1, compWith;

    while (i < n)
    {
        if (preOrd[i] < ptr->data)
        {
            newNode = new BinNode;
            newNode->newNode(preOrd[i++]);
            ptr->left = newNode;
            stk.push(ptr);
            ptr = newNode;
        }
        else if (preOrd[i] > ptr->data)
        {
            compWith = (stk.isEmpty()) ? INT_MAX : stk.stackTop()->data;
            if (preOrd[i] < compWith)
            {
                newNode = new BinNode;
                newNode->newNode(preOrd[i++]);
                ptr->right = newNode;
                ptr = newNode;
            }
            else if (preOrd[i] > compWith && !stk.isEmpty())
                ptr = stk.pop();
        }
    }
}

void BinarySearchTree::createFromPost(int *postOrd, int n)
{
    if (root)
        return;
    root = new BinNode;
    root->newNode(postOrd[n - 1]);

    BinNode *newNode, *ptr = root;
    Stack<BinNode *> stk;
    int i = n - 2, compWith;

    while (i >= 0)
    {
        if (postOrd[i] > ptr->data)
        {
            newNode = new BinNode;
            newNode->newNode(postOrd[i--]);
            ptr->right = newNode;
            stk.push(ptr);
            ptr = newNode;
        }
        else if (postOrd[i] < ptr->data)
        {
            compWith = (stk.isEmpty()) ? INT_MIN : stk.stackTop()->data;
            if (postOrd[i] > compWith)
            {
                newNode = new BinNode;
                newNode->newNode(postOrd[i--]);
                ptr->left = newNode;
                ptr = newNode;
            }
            else if (postOrd[i] < compWith && !stk.isEmpty())
                ptr = stk.pop();
        }
    }
}

BinarySearchTree::~BinarySearchTree()
{
    Queue<BinNode *> que;
    que.enqueue(root);
    BinNode *temp;
    while (!que.isEmpty())
    {
        temp = que.dequeue();
        if (temp->left)
            que.enqueue(temp->left);
        if (temp->right)
            que.enqueue(temp->right);
        delete temp;
    }
    root = NULL;
    cout << "Binary Search Tree destructed\n";
}

int main()
{
    int arr[] = {20, 30, 10, 40};
    BinarySearchTree b(arr, 4, 1);
    b.rInsert(100);
    b.insert(5);
    b.rInsert(23);
    b.insert(7);
    b.rInsert(15);
    b.insert(4);
    b.rInsert(37);
    b.deleteEle(30);
    b.deleteEle(0); // element is not in tree
    cout << "30 found at address: " << b.rSearch(30) << "\n";
    cout << "20 found at address: " << b.search(20) << "\n";
    b.inOrder();
    return 0;
}