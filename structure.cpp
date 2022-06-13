#include <bits/stdc++.h>
using namespace std;
int main()
{
    // cout<<"hello world"<<endl;
    struct rectangle
    {
        int length;
        int breadth;
    };
    struct square{
        int side;
        int area= side*side;
    };

    rectangle r1;
    r1.length = 10;
    r1.breadth = 20;

    square s1;
    s1.side = 10;

    cout << "length=" << r1.length << endl;
    cout << "breadth=" << r1.breadth << endl;
    cout << "area=" << s1.area << endl;
    
    return 0;
}
