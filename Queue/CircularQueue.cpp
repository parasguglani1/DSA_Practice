// Demonstrating circular queues
#include "CircularQueue.h"

/* Drawbacks of Queue using Arrays:
1. Cannot use spaces of deleted elements;
2. Every location can be used only once;
3. The queue could be considered empty and full at the same time;

Solutions:
1. Reset pointers by reinitializing them to -1 when front == rear, but it doesn't guarantee
the use of free spaces if they never come to be equal;
2. Circular queue, a better solution: front and rear will start from 0 (not -1 as done previously)
and with an insertion the element should be placed to index 1, index 0 should be left empty.
When rear == size - 1, if there have been dequeued elements, check if 0 is empty (but the front
pointer mustn't be pointing at 0, since where it points to must always be empty) and if so, enqueue
the new element in the "beginning" of the array, thus the "circular". This is done using a modulo
operation: rear = (rear + 1) % size

*/

int initializer()
{
    int var;
    while (true)
    {
        cout << "Enter the maximum size of the queue: ";
        cin >> var;
        if (var > 0)
            break;
        cout << "Invalid size, retry with a positive number\n";
    }
    return var;
}

int main()
{
    int choice;
    int ele;                     // change ele's data type to employ generic nature
    Queue<int> q(initializer()); // change the tag here
    while (true)
    {
        // if(q.isEmpty() && q.isFull()) - not needed for circular queue

        cout << "1. Enqueue an element\n2. Dequeue an element\n3. Get the first queue element\n";
        cout << "4. Get the last queue element\n5. Check if the queue is full or empty\n";
        cout << "6. Display all the queue elements\n0. Exit the menu\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (!q.isFull())
            {
                cout << "Enter an element to be inserted: ";
                cin >> ele;
                /* Use
                cin>>ws; getline(cin, ele);
                for string*/
                q.enqueue(ele);
            }
            else
                cout << "Cannot insert element since queue is full\n";
            break;
        }
        case 2:
        {
            if (!q.isEmpty())
                cout << "Element dequeued: " << q.dequeue() << "\n";
            else
                cout << "Cannot delete element since queue is empty\n";
            break;
        }
        case 3:
        {
            if (!q.isEmpty())
                cout << "First queue element is: " << q.atFront() << "\n";
            else
                cout << "Cannot display element since queue is empty\n";
            break;
        }
        case 4:
        {
            if (!q.isEmpty())
                cout << "Last queue element is: " << q.atRear() << "\n";
            else
                cout << "Cannot display element since queue is empty\n";
            break;
        }
        case 5:
        {
            if (q.isEmpty())
                cout << "Queue is empty\n";
            else if (q.isFull())
                cout << "Queue is full\n";
            else
                cout << "Queue is neither full nor empty\n";
            break;
        }
        case 6:
        {
            if (!q.isEmpty())
                cout << "The queue elements are:\n"
                     << q;
            else
                cout << "Cannot print elements since queue is empty\n";
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid choice, try again\n";
        }
        cout << "-----------------------\n";
        if (!choice)
        {
            cout << "Menu terminated\n";
            break;
        }
    }
    return 0;
}