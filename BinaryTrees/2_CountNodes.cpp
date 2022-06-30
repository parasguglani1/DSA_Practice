
#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    // printLevelorder(root);
    cout << countNodes(root);
    return 0;
}