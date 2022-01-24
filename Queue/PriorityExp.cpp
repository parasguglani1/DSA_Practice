/*Implementing a priority queue where every element has an associated explicit priority
Using queues implemented using linked lists*/
#include "QueueLL.h"

template <typename T>
class Priority
{
    private:
    Queue<T>* qtr;
    int nPrior;
    public:
    Priority()
    {
        qtr = NULL;
        nPrior = 2; //default value
    }
    Priority(int);
    void enqueue(T, int);
    T dequeue();
    bool isEmpty();
    ~Priority();
    template <typename U>
    friend ostream& operator <<(ostream&, Priority<U>&);
};

template <typename T>
Priority<T>::Priority(int n)
{
    if(n > 0)
        nPrior = n;
    qtr = new Queue<T>[nPrior];
}

template <typename T>
void Priority<T>::enqueue(T toInsert, int priority)
{
    if(priority >= 1 && priority <= nPrior)
    {
        if(!qtr[priority-1].isFull())
            qtr[priority-1].enqueue(toInsert);
        else
            cout<<"Cannot enqueue more elements due to overflow\n";
    }
    else 
        cout<<"Invalid priority passed, cannot enqueue\n";
}

template <typename T>
T Priority<T>::dequeue()
{
    int i = 0; T var;
    while(qtr[i].isEmpty() && i < nPrior)
        ++i;
    if(qtr[i].isEmpty())
        cout<<"Cannot dequeue since priority queue is empty\n";
    else
        var = qtr[i].dequeue();
    return var;
}

template <typename T>
bool Priority<T>::isEmpty()
{
    int i = 0;
    while(i < nPrior)
    {
        if(!qtr[i].isEmpty())
            return false;
        ++i;
    }
    return true;
}

template <typename T>
ostream& operator <<(ostream& out, Priority<T>& p)
{
    if(p.isEmpty())
        out<<"Cannot display since priority queue is empty\n";
    else
    {
        int i = 0;
        while(i < p.nPrior)
        {
            out<<"Priority "<<i+1<<": ";
            if(!(p.qtr[i]).isEmpty()) //do not need parentheses since in qtr[i].isEmpty(), qtr[i] is executed first
                out<<p.qtr[i];
            else
                out<<"<---Empty--->\n";
            i++;                    
        }
    }
    return out;
}

template <typename T>
Priority<T>::~Priority()
{
    /*for(int i = 0; i < nPrior; i++)
        qtr[i].~Queue();*/
    delete []qtr; //commented code and this line are equivalent
    cout<<"Priority queue object destructed\n";   
}

int initializer()
{
    int var;
    while(true)
    {
        cout<<"Enter the number of priorities: ";
        cin>>var;
        if(var > 0)
            break;
        cout<<"Invalid input, retry with a positive number\n";
    }
    return var;
}

int main()
{
    int priorities = initializer(), choice, pr;
    int ele; //change the data type to observe generic nature
    Priority<int> p(priorities); //change the tag to switch data types
    while(true)
    {
        cout<<"1. Enqueue an element\n2. Dequeue an element\n3. Display the priority queue\n";
        cout<<"0. Quit the menu\nEnter your choice: "; cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter the element: "; cin>>ele;
                while(true)
                {
                    cout<<"Enter the element priority: ";
                    cin>>pr;
                    if(pr >= 1 && pr <= priorities)
                        break;
                    cout<<"Invalid input, enter a number between 1 and "<<priorities<<"\n";
                }
                p.enqueue(ele, pr);
                break;
            }
            case 2:
            {
                if(p.isEmpty())
                    cout<<"Cannot dequeue because the queue is empty\n";
                else
                    cout<<"Dequeued element "<<p.dequeue()<<" on a priority basis\n";
                break;
            }
            case 3:
            {
                if(p.isEmpty())
                    cout<<"Cannot display since priority queue is empty\n";
                else
                {
                    cout<<"The priority queue elements are:\n";
                    cout<<p;
                }
                break;
            }
            case 0:
                break;
            default:
                cout<<"Invalid input, try again\n";
        }
        cout<<"-----------------------\n";
        if(choice == 0)
        {
            cout<<"Menu terminated\n";
            break;
        }
    }
    return 0;
}