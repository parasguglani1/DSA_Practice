#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;
    TreeNode(T data);
    void printTreeRecursive(TreeNode<T> *root);
    TreeNode<T> takeInputRecursive();
    ~TreeNode();
};

template <typename T>
TreeNode<T>::TreeNode(T data)
{
    this->data = data;
}

/*
Print tree recursive function can only be called on objects of type TreeNode. so I used normal functions instead of this.
template <typename T>
void TreeNode<T>::printTreeRecursive(TreeNode<T> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        printTreeRecursive(root->children[i]);
    }
} */
template <typename T>
TreeNode<T>::~TreeNode()
{
    for (int i = 0; i < children.size(); i++)
    {
        delete children[i];
    }
}

void printTreeRecursive(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " , ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTreeRecursive(root->children[i]);
    }
}
// Take input recursive
TreeNode<int> *takeInputRecursive()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInputRecursive();
        root->children.push_back(child);
    }
    return root;
}

void printLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data;
            if ((i + 1) < front->children.size())
            {
                cout << ",";
            }
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}
// Level Traversal take Input
TreeNode<int> *takeInputLevelOrder()
{
    int rootData;
    cout << "Enter the root element : ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *node = q.front();
        q.pop();
        int n;
        cout << "Enter the number of children for " << node->data << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the " << i << "th element for " << node->data << endl;
            int num;
            cin >> num;
            TreeNode<int> *newNode = new TreeNode<int>(num);
            node->children.push_back(newNode);
            q.push(newNode);
        }
    }
    return root;
}

// int main()
// {
//     TreeNode<int> *root = new TreeNode<int>(1);
//     root->children.push_back(new TreeNode<int>(2));
//     root->children.push_back(new TreeNode<int>(3));
//     root->children.push_back(new TreeNode<int>(4));

//     root->children[0]->children.push_back(new TreeNode<int>(5));
//     root->children[0]->children.push_back(new TreeNode<int>(6));
//     root->children[1]->children.push_back(new TreeNode<int>(6));

//     printTreeRecursive(root);
//     // root->printTreeRecursive(root);
//     return 0;
// }
