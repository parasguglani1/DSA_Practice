
#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;
int countNodes(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    int count = 1;
    count += countNodes(root->left);
    count += countNodes(root->right);
    return count;
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    // printLevelorder(root);
    cout << countNodes(root);
    return 0;
}