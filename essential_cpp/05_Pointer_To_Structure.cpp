#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r;

    // Access the structure variable by using 'r' variable
    r.length = 15;
    r.breadth = 20;
    std::cout << "length: " << r.length << ", "
              << "breadth: " << r.breadth << "\n";

    // Access the structure variable by using 'ptrC' variable (C style)
    struct Rectangle *ptrC;
    ptrC = &r;
    (*ptrC).length = 25;
    (*ptrC).breadth = 25;
    std::cout << "length: " << (*ptrC).length << ", "
              << "breadth: " << (*ptrC).breadth << "\n";

    // Access the structure variable by using 'ptrCPlusPlus' variable (C++ style)
    struct Rectangle *ptrCPlusPlus;
    ptrCPlusPlus = &r;
    ptrCPlusPlus->length = 30;
    ptrCPlusPlus->breadth = 40;
    std::cout << "length: " << ptrCPlusPlus->length << ", "
              << "breadth: " << ptrCPlusPlus->breadth << "\n";

    // As the address of 'r' is stored in the pointer variables, therefore the value of r is also changed
    std::cout << "length: " << r.length << ", "
              << "breadth: " << r.breadth << "\n";

    struct Rectangle rArr[3];
    rArr[0].length = 10;
    rArr[0].breadth = 11;

    rArr[1].length = 12;
    rArr[1].breadth = 13;

    rArr[2].length = 14;
    rArr[2].breadth = 15;

    for (int i = 0; i < 3; ++i)
        cout << rArr[i].length << " " << rArr[i].breadth << '\n';

    // Arrays of structures (C style)
    struct Rectangle *ptrArrHeap;
    ptrArrHeap = (struct Rectangle *)malloc(3 * sizeof(Rectangle));

    ptrArrHeap[0].length = 16;
    ptrArrHeap[0].breadth = 17;

    ptrArrHeap[1].length = 18;
    ptrArrHeap[1].breadth = 19;

    ptrArrHeap[2].length = 20;
    ptrArrHeap[2].breadth = 21;

    for (int i = 0; i < 3; ++i)
        cout << ptrArrHeap[i].length << " " << ptrArrHeap[i].breadth << '\n';

    return 0;
}