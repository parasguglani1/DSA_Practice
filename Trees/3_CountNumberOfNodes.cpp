#include <bits/stdc++.h>
#include "Tree.cpp"

using namespace std;

int main()
{
    TreeNode<int> *root = takeInputLevelOrder();
    cout << countNodes(root) << endl;
    return 0;
}