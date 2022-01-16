//Simple tree recursion program
//Commented code can be used for additional debugging
#include <iostream>
using namespace std;

//int calls = 0;
void func(int n)
{
    //calls++;
    //cout<<"\nCall number: "<<calls;
    if(n > 0)
    {
        //cout<<"\nOutput: "<<n<<"\n";
        cout<<n<<" ";
        func(n-1);
        func(n-1);
    }
}

int main()
{
    cout<<"Enter a positive number: ";
    int num; 
    while(true)
    {
        cin>>num;
        if(num > 0)
            break;
        else 
            cout<<"Invalid input, try again\n";
    }

    func(num);
    //cout<<"\nTotal number of calls: "<<calls<<"\n";
    return 0;
}