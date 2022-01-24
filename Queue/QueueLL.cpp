#include "QueueLL.h"

int main()
{
    int choice; int ele; //change ele's data type to employ generic nature
    Queue<int> q; //change the tag here 
    while(true)
    {
        cout<<"1. Enqueue an element\n2. Dequeue an element\n3. Get the first queue element\n";
        cout<<"4. Get the last queue element\n5. Check if the queue is full or empty\n";
        cout<<"6. Display all the queue elements\n0. Exit the menu\nEnter your choice: "; cin>>choice;

        switch(choice)
        {
            case 1:
            {
                if(!q.isFull())
                {
                    cout<<"Enter an element to be inserted: "; cin>>ele;
                    /* Use
                    cin>>ws; getline(cin, ele);
                    for string*/
                    q.enqueue(ele);
                }
                else
                    cout<<"Cannot insert element since queue is full\n";
                break;
            }
            case 2:
            {
                if(!q.isEmpty())
                    cout<<"Element dequeued: "<<q.dequeue()<<"\n";
                else
                    cout<<"Cannot delete element since queue is empty\n";
                break;
            }
            case 3:
            {
                if(!q.isEmpty())
                    cout<<"First queue element is: "<<q.atFront()<<"\n";
                else
                    cout<<"Cannot display element since queue is empty\n";
                break;
            }
            case 4:
            {
                if(!q.isEmpty())
                    cout<<"Last queue element is: "<<q.atRear()<<"\n";
                else
                    cout<<"Cannot display element since queue is empty\n";
                break;
            }
            case 5:
            {
                if(q.isEmpty())
                    cout<<"Queue is empty\n";
                else if(q.isFull())
                    cout<<"Queue is full\n";
                else
                    cout<<"Queue is neither full nor empty\n";
                break;
            }
            case 6:
            {
                if(!q.isEmpty())
                    cout<<"The queue elements are:\n"<<q;
                else
                    cout<<"Cannot print elements since queue is empty\n";
                break;
            }
            case 0:
                break;
            default:
                cout<<"Invalid choice, try again\n";
        }
        cout<<"-----------------------\n";
        if(!choice)
        {
            cout<<"Menu terminated\n";
            break;
        }
    }
    return 0;
}