#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{

public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data);
    ~BinaryTreeNode();
};
template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(T data)
{
    this->data = data;
    left = NULL;
    right = NULL;
}

template <typename T>
BinaryTreeNode<T>::~BinaryTreeNode()
{
    delete left;
    delete right;
}
BinaryTreeNode<int> *takeInputRecursive()
{
    cout << "enter data " << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    BinaryTreeNode<int> *left = takeInputRecursive();
    root->left = left;
    BinaryTreeNode<int> *right = takeInputRecursive();
    root->right = right;
    return root;
}
void printRecursive(BinaryTreeNode<int> *root)
{

    if (!root)
    {
        return;
    }
    cout << root->data << " : ";
    if (root->left)
    {
        cout << "L - ";
        cout << root->left->data << " , ";
    }

    if (root->right)
    {
        cout << "R - ";
        cout << root->right->data;
    }
    cout << endl;
    printRecursive(root->left);
    printRecursive(root->right);
}

BinaryTreeNode<int> *taktInputLevelorder()
{
    // cout << "enter root data" << endl;
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        // cout << "enter left child of " << front->data << " : ";
        int data;
        cin >> data;
        if (data != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(data);
            front->left = leftNode;
            pendingNodes.push(leftNode);
        }
        // cout << "enter right child of " << front->data << " : ";
        cin >> data;
        if (data != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(data);
            front->right = rightNode;
            pendingNodes.push(rightNode);
        }
    }

    return root;
}

void printLevelorder(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    // cout << root->data << ": ";
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left)
        {
            cout << "L:" << front->left->data << ",";
            pendingNodes.push(front->left);
        }
        else
        {
            cout << "L:-1,";
        }
        if (front->right)
        {
            cout << "R:" << front->right->data;
            pendingNodes.push(front->right);
        }
        else
        {
            cout << "R:-1";
        }
        cout << endl;
    }
}

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}