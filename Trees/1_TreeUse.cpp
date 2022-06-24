#include <bits/stdc++.h>
#include "Tree.cpp"

using namespace std;
int main()
{
    TreeNode<int> *root = takeInputRecursive();

    printTreeRecursive(root);

    return 0;
}