#include <bits/stdc++.h>

using namespace std;

/**
 *  Reverse a Stack
 *  -   You have been given two stacks that can store integers as the data.
 *      Out of the two given stacks, one is populated and the other one is
 *      empty. You are required to write a function that reverses the populated
 *      stack using the one which is empty.
 *
 *  Input Format :
 *      The first line of input contains an integer N, denoting the total
 *      number of elements in the stack.
 *      The second line of input contains N integers separated by a single
 *      space, representing the order in which the elements are pushed into the stack.
 *  Output Format:
 *      The only line of output prints the order in which the stack elements are
 *      popped, all of them separated by a single space.
 *
 *  Constraints:
 *      1 <= N <= 10^3
 *      -2^31 <= data <= 2^31 - 1
 *
 *  Time Limit: 1sec
 *
 *  Sample Input 1:
 *      6
 *      1 2 3 4 5 10
 *  Note: Here, 10 is at the top of the stack.
 *  Sample Output 1:
 *      1 2 3 4 5 10
 *  Note: Here, 1 is at the top of the stack.
 *
 *  Sample Input 2:
 *      5
 *      2 8 15 1 10
 *  Sample Output 2:
 *      2 8 15 1 10
 */
// stores reversed stack in original stack
void reverseStack(stack<int> &input, stack<int> &extra)
{
    if (input.empty())
    {
        return;
    }
    int temp = input.top();
    input.pop();
    reverseStack(input, extra);
    while (!input.empty())
    {
        int t = input.top();
        input.pop();
        extra.push(t);
    }
    input.push(temp);
    while (!extra.empty())
    {
        int t = extra.top();
        extra.pop();
        input.push(t);
    }
}

int main()
{
    stack<int> input, extra;
    int size;
    cin >> size;
    for (int i = 0, val; i < size; i++)
    {
        cin >> val;
        input.push(val);
    }
    reverseStack(input, extra);
    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
}
/*

// C++ program to implement Stack
// using linked list so that reverse
// can be done with O(1) extra space.
#include <bits/stdc++.h>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;

    StackNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{

    StackNode *top;

public:
    // Push and pop operations
    void push(int data)
    {
        if (top == NULL)
        {
            top = new StackNode(data);
            return;
        }
        StackNode *s = new StackNode(data);
        s->next = top;
        top = s;
    }

    StackNode *pop()
    {
        StackNode *s = top;
        top = top->next;
        return s;
    }

    // prints contents of stack
    void display()
    {
        StackNode *s = top;
        while (s != NULL)
        {
            cout << s->data << " ";
            s = s->next;
        }
        cout << endl;
    }

    // Reverses the stack using simple
    // linked list reversal logic.
    void reverse()
    {
        StackNode *prev, *cur, *succ;
        cur = prev = top;
        cur = cur->next;
        prev->next = NULL;
        while (cur != NULL)
        {

            succ = cur->next;
            cur->next = prev;
            prev = cur;
            cur = succ;
        }
        top = prev;
    }
};

// driver code
int main()
{
    Stack *s = new Stack();
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    cout << "Original Stack" << endl;
    ;
    s->display();
    cout << endl;

    // reverse
    s->reverse();

    cout << "Reversed Stack" << endl;
    s->display();

    return 0;
}
*/
