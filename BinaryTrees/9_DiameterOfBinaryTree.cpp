#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;
#define ff first
#define ss second
//
// 1 2 3 4 5 - 1 - 1 6 - 1 - 1 7 8 - 1 - 1 9 - 1 - 1 - 1 - 1
// 5
// 6
int getDiameter(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    int maxHeight = leftHeight + rightHeight;
    int maxD = (getDiameter(root->left), getDiameter(root->right));
    return (max(maxHeight, maxD));
}

// first is height second is dia
pair<int, int> getHeightDiameter(BinaryTreeNode<int> *root)
{
    pair<int, int> p = {0, 0};
    if (!root)
    {
        return p;
    }
    pair<int, int> leftAns = getHeightDiameter(root->left);
    pair<int, int> rightAns = getHeightDiameter(root->right);
    int lh = leftAns.ff;
    int ld = leftAns.ss;
    int rh = rightAns.ff;
    int rd = rightAns.ss;
    int height = 1 + max(lh, rh);
    int diameter = max(ld, max(rd, lh + rh));
    pair<int, int> ans = {height, diameter};
    return ans;
}
int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    // cout << getDiameter(root);// complexity n*h
    // h is logn in case of balanced tree and n in case of one sided tree
    cout << getHeightDiameter(root).ff << endl;
    cout << getHeightDiameter(root).ss << endl;

    return 0;
}