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
template <typename T>
TreeNode<T>::~TreeNode()
{
    for (int i = 0; i < children.size(); i++)
    {
        delete children[i];
    }
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

void printLevelATNewLine(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode<int> *first = q.front();
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
        for (int i = 0; i < first->children.size(); i++)
        {
            q.push(first->children[i]);
        }
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
// without interactive statements
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

/**
 *  Count Number of Nodes
 */
int countNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNodes(root->children[i]);
    }
    return ans;
}

int sumOfNodes(TreeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}

TreeNode<int> *nodeWithLargestData(TreeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    TreeNode<int> *largest = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *curr = nodeWithLargestData(root->children[i]);
        if (curr->data > largest->data)
        {
            largest = curr;
        }
    }
    return largest;
}

int getHeight(TreeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    int height = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        height = max(height, getHeight(root->children[i]));
    }
    return height + 1;
}

void preOrderTraversal(TreeNode<int> *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";

    for (int i = 0; i < root->children.size(); i++)
    {
        preOrderTraversal(root->children[i]);
    }

    return;
}

void postOrderTraversal(TreeNode<int> *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";

    for (int i = 0; i < root->children.size(); i++)
    {
        postOrderTraversal(root->children[i]);
    }

    return;
}

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (!root)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}
bool containsX(TreeNode<int> *root, int key)
{
    if (!root)
        return false;
    if (root->data == key)
    {
        return true;
    }
    bool found = false;
    for (int i = 0; i < root->children.size(); i++)
    {
        found = found || containsX(root->children[i], key);
    }
    return found;
}
int CountGreaterThanX(TreeNode<int> *root, int x)
{
    if (!root)
        return 0;
    int count = 0;
    if (root->data > x)
        count++;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += CountGreaterThanX(root->children[i], x);
    }
    return count;
}

// first is treenode second is sum
pair<TreeNode<int> *, int> nodeWithMaxChildSum(TreeNode<int> *root)
{
    pair<TreeNode<int> *, int> ans;
    if (!root)
    {
        ans.first = 0;
        ans.second = 0;
        return ans;
    }
    TreeNode<int> *largest = root;

    int largestSum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        largestSum += (root->children[i]->data);
    }
    ans.first = root;
    ans.second = largestSum;
    for (int i = 0; i < root->children.size(); i++)
    {
        pair<TreeNode<int> *, int> ans2 = nodeWithMaxChildSum(root->children[i]);
        if (ans2.second > ans.second)
        {
            ans.second = ans2.second;
            ans.first = ans2.first;
        }
    }
    return ans;
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
