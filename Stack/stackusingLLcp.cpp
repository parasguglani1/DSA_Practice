
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(/* args */);
    ~Node();
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
template <typename T>
class stackusingLL
{
private:
    // int data;
    Node<T> *head;
    int size = 0;

public:
    stackusingLL()
    {
        Node<T> *head = NULL;
    }
    void push(T ele)
    {
        Node<T> *newNode = new Node(ele);
        if (!head)
        {
            head = newNode;
            size++;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            size++;
        }
    }
    T pop()
    {
        if (isEmpty())
            return INT_MIN;
        T ele = head->data;
        head = head->next;
        size--;
        return ele;
    }
    int getsize()
    {
        return size;
    }
    int top()
    {
        return head->data;
    }
    bool isEmpty()
    {
        return !size;
    }
};

int main()
{
    stackusingLL<int> st1;
    st1.push(15);
    st1.push(25);
    cout << st1.getsize() << endl;
    cout << st1.isEmpty() << endl;

    cout << st1.top() << endl;
    cout << st1.pop() << endl;
    cout << st1.top() << endl;
    cout << st1.getsize() << endl;

    cout << st1.pop() << endl;
    cout << st1.isEmpty() << endl;

    return 0;
}