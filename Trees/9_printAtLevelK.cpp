#include <bits/stdc++.h>
#include "Tree.cpp"
using namespace std;
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
// 2
// output 5 6 7 8

int main()
{
    TreeNode<int> *root = takeInputLevelOrder();
    int k;
    cin >> k;
    printAtLevelK(root, k);
    return 0;
}
