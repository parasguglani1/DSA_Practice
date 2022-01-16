//Static variables in recursion
#include <iostream>
using namespace std;

int sumOfN(int x)
{
    if(x > 0)
        return sumOfN(x-1)+x;
    else 
        return 0;
}

/*'a' is not added in its step-incremented value
Rather, its last value is added every time
Thus, (read upside down)
Square(5) = Square(4) + 20 = 25         a = 0
Square(4) = Square(3) + 5 = 20          a = 1
Square(3)= Square(2) + 5 = 15           a = 2
Square(2)= Square(1) + 5 = 10           a = 3
Square(1)= Square(0) + 5 = 5            a = 4
Square(0) = 0                           a = 5
*/
//int a = 0; - global and static variables work just the same

int Square(int x)
{
    static int a = 0;
    //Removing static makes it add 1 every time, which results in the input
    if(x > 0)
    {
        a++;
        return Square(x-1)+a;
    }
    else 
        return 0;
}

int main()
{
    cout<<"Enter a positive number: ";
    unsigned int num;
    while(true)
    {
        cin>>num;
        if(num <= 0)
            cout<<"Invalid input, try again\n";
        else 
            break;
    }

    cout<<"Sum of first "<<num<<" natural numbers: "<<sumOfN(num)<<"\n";
    cout<<"The square of "<<num<<" is: "<<Square(num)<<"\n";

    return 0;
}