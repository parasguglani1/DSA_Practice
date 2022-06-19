/* Coding Problem
Problem Statement: Reverse LL (Iterative) 
Problem Level: EASY
Problem Description:
Given a linked list, reverse it iteratively.
You don't need to print the elements, just reverse the LL duplicates and return the head of updated LL.
`Input format : Linked list elements (separated by space and terminated by -1)``

Sample Input 1 :
1 2 3 4 5 -1

Sample Output 1 :
5 4 3 2 1

 */
#include <bits/stdc++.h>
using namespace std;
#include "myLinkedlist.cpp"

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = inputTillNegativeOne();
        head = reverseIterative(head);

        print(head);
    }
    //we can use stack as well to reverse ll

    return 0;
}