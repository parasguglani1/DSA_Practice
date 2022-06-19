/* Problem Statement: Swap two Nodes of LL
Problem Level: MEDIUM
Problem Description:
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th'  and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.

Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4

Sample Output 1 :
3 4 5 6 2 1 9

Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6

Sample Output 2 :
10 30 20 40
90 80 90 25 65 85 70
 */

#include <bits/stdc++.h>
using namespace std;
#include "myLinkedlist.cpp"
//similar but clean
Node *swapNodes(Node *head, int m, int n)
{
    if (m == n || head == NULL || head->next == NULL)
    {
        return head;
    }
    // choose i as smaller and j as greater
    int i = (m < n) ? m : n;
    int j = (i == m) ? n : m;

    Node *previous1 = NULL;
    Node *previous2 = NULL;
    Node *curr1 = head;
    Node *curr2 = head;
    int a = 0;
    while (curr1 != NULL && a < i)
    {
        previous1 = curr1;
        curr1 = curr1->next;
        a++;
    }
    a = 0;
    while (curr2 != NULL && a < j)
    {
        previous2 = curr2;
        curr2 = curr2->next;
        a++;
    }

    // if i==0 and |i-j| == 1 i.e. one index is zero and are adjacent elements
    if (i == 0 && (j - i) == 1)
    {
        curr1->next = curr2->next;
        curr2->next = previous2;
        head = curr2;
        // if |i-j| == 1 i.e. are adjacent elements
    }
    else if ((j - i) == 1)
    {
        previous1->next = curr2;
        curr1->next = curr2->next;
        curr2->next = previous2;
        // if i==0 i.e. one index is zero
    }
    else if (i == 0)
    {
        previous2->next = curr1;
        Node *temp = curr1->next;
        curr1->next = curr2->next;
        curr2->next = temp;
        head = curr2;
        // else for any other normal case.
    }
    else
    {
        previous1->next = curr2;
        previous2->next = curr1;
        Node *temp = curr1->next;
        curr1->next = curr2->next;
        curr2->next = temp;
    }
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        Node *head = inputTillNegativeOne();
        Node *temp = head;
        int i, j;
        cin >> i >> j;
        int count = 0;
        Node *prev1 = head;
        Node *prev2 = head;
        Node *Node1 = head;
        Node *Node2 = head;
        // make sure j is always greater
        if (i > j)
        {
            swap(i, j);
        }
        if (i == 0 && j == 1)
        {
            Node *temp3 = head->next->next;
            Node1=head;
            head=head->next;
            head->next=Node1;
            Node1->next= temp3;

        
        }
         else if (i == 0)
        {
            while (temp && count <= j - 1)
            {

                prev2 = temp;
                temp = temp->next;
                // cout << count << " " << endl;
                count++;
            }
            Node1 = head;
            Node2 = prev2->next;

            Node *temp1 = Node1->next;
            Node1->next = Node2->next;
            Node2->next = temp1;
            head = Node2;
            prev2->next = Node1;
        }

        else if (i == j)
            continue;
        else if ((j - i) == 1)
        {
            while (temp && count <= i - 1)
            {
                prev1 = temp;

                temp = temp->next;
                // cout << count << " " << endl;
                count++;
            }
            Node1 = prev1->next;
            Node2 = Node1->next;
            Node1->next = Node2->next;
            prev1->next = Node2;
            Node2->next = Node1;
        }
        else
        {
            if (temp && (count <= j))
            {
                while (temp && count <= i - 1)
                {
                    prev1 = temp;
                    prev2 = temp;

                    temp = temp->next;
                    // cout << count << " " << endl;
                    count++;
                }
                while (temp && count <= j - 1)
                {
                    prev2 = temp;
                    temp = temp->next;
                    // cout << "j ";
                    // cout << count << " " << endl;
                    count++;
                }
            }
            // cout<<i <<" "<<j<<endl;
            // cout << prev1->data << " " << prev2->data << endl;
            Node1 = prev1->next;
            Node2 = prev2->next;
            // cout << Node1->data << " " << Node2->data << endl;

            Node *temp1 = Node1->next;
            Node1->next = Node2->next;
            Node2->next = temp1;
            prev1->next = Node2;
            prev2->next = Node1;
        }
        print(head);
    }

    return 0;
}