//Implementing stacks using an array
#include "Stacks.h"

int main()
{
    Stack<string> stk(initializer()); //template
    int choice;
    while(true)
    {
        cout<<"1. Push an element\n2. Pop an element\n3. Peek at desired index\n";
        cout<<"4. Obtain latest entry\n5. Display the stack\n6. Check if the stack is full/empty\n";
        cout<<"0. Quit the menu\nEnter your choice: "; cin>>choice;
        switch(choice)
        {
            case 1:
            {
                if(!stk.isFull())
                {
                    cout<<"Enter the element to be pushed: ";
                    string ele; cin>>ws; getline(cin, ele);
                    /* Uncomment and change the tag above to use various types
                        int ele; char ele; float ele; double ele;
                        cin>>ele;
                    */
                    stk.push(ele);
                }
                else
                    cout<<"Cannot insert new element, Stack Overflow\n";
                break;
            }
            case 2:
            {
                if(!stk.isEmpty())
                    cout<<"Popped element: "<<stk.pop()<<"\n";
                else
                    cout<<"Cannot pop element, Stack Underflow\n";
                break;
            }
            case 3:
            {
                if(!stk.isEmpty())
                {
                    int ind, top = stk.getTop();
                    while(true)
                    {
                        cout<<"Enter the index to peek: ";
                        cin>>ind;
                        if(ind >= 1 && ind <= top+1)
                            break;
                        cout<<"Invalid input, retry with a number between 1 and "<<top+1<<"\n";
                    }
                    cout<<"Element at index "<<ind<<" from the top: "<<stk.peek(ind)<<"\n";
                }
                else
                    cout<<"Cannot peek, stack underflow\n";
                break;
            }
            case 4:
            {
                if(!stk.isEmpty())
                    cout<<"Last inserted element: "<<stk.stackTop()<<"\n";
                else
                    cout<<"Stack is empty, Stack Underflow\n";
                break;
            }
            case 5:
            {
                if(!stk.isEmpty())
                {
                    for(int i = 1; i <= stk.getTop()+1; i++)
                        cout<<stk.peek(i)<<"\n";
                }
                else
                    cout<<"Stack is empty, Stack Underflow\n";
                break;
            }
            case 6:
            {
                if(stk.isEmpty())
                    cout<<"Stack is empty\n";
                else if(stk.isFull())
                    cout<<"Stack is full\n";
                else
                    cout<<"Stack is neither empty nor full\n";
            }
            case 0:
                break;
            default:
                cout<<"Invalid choice, try again\n";
        }
        if(choice == 0)
        {
            cout<<"Menu terminated\n";
            break;
        }
        cout<<"------------------------\n";
    }
    return 0;
}