//A simple program to demonstrate recursion and the effect of changing the code order ever so slightly
#include <iostream>
using namespace std;

void head(int n)
{
    if(n > 0)
    {
        head(n-1); 
        cout<<n<<" "; //works while it descends back
    }
}

void tail(int n)
{
    if(n > 0)
    {
        cout<<n<<" "; //works in the ascending phase itself
        tail(n-1);
    }
}

int main()
{
    cout<<"Enter a positive number:\n";
    unsigned short int n;
    while(true) //input validator
    {
        cin>>n;
        if(n <= 0)
            cout<<"Invalid input, try again\n";
        else 
            break;
    }

    cout<<"Numbers printed from 1 to "<<n<<":\n"; head(n); //call to first recursive function
    cout<<"\nNumbers printed from "<<n<<" to 1:\n"; tail(n); //call to second recursive function
    
    return 0;
}