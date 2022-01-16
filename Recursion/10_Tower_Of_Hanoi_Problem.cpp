//Solving the Tower of Hanoi problem
#include <iostream>
#include <cmath>
using namespace std;

int calls = 0;
void TowerOfHanoi(int n, char a, char b, char c)
{
    calls++;//tracking number of calls
    if(n > 0)
    {
        TowerOfHanoi(n-1, a, c, b);
        cout<<"Disk shifted from tower "<<a<<" to tower "<<c<<"\n";//total prints = pow(2,n)
        TowerOfHanoi(n-1, b, a, c);
    }
}

int main()
{
    cout<<"Enter the number of disks on tower A: ";
    int disks; 
    while(true)
    {
        cin>>disks;
        if(disks > 0)
            break;
        cout<<"Invalid input, enter a whole number: ";
    }

    cout<<"Steps to follow to shift "<<disks<<" disks from tower A to C, using B:\n";
    TowerOfHanoi(disks, 'A', 'B', 'C');
    //if(calls == ((int)pow(2, disks+1) - 1)) - formula
    cout<<"Number of calls = "<<calls<<"\n";

    return 0;
}
