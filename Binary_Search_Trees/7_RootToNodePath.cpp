#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;

void preOrderPrint(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

/**
 *  Root to Node Path - Binary Tree
 *
 */
vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == k)
    {
        vector<int> *res = new vector<int>();
        res->push_back(root->data);
        return res;
    }
    vector<int> *left = getRootToNodePath(root->left, k);
    if (left != NULL)
    {
        left->push_back(root->data);
        return left;
    }
    vector<int> *right = getRootToNodePath(root->right, k);
    if (right != NULL)
    {
        right->push_back(root->data);
        return right;
    }
    return NULL;
}

int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int> *root = taktInputLevelorder();
    int k;
    cin >> k;
    vector<int> *output = getRootToNodePath(root, k);
    if (output != NULL)
    {
        for (int i = output->size() - 1; i >= 0; i--)
        {
            cout << output->at(i) << " ";
        }
    }

    return 0;
}