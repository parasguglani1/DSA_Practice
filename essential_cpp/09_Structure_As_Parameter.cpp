#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

// ------------------------------- Call By Value ---------------------------
/*
void fun(struct Rectangle r1)
{
    r1.length = 20;
    cout << "Length: " << r1.length << ", Breadth: " << r1.breadth << '\n';
}

int main()
{
    struct Rectangle r = {10, 5};
    fun(r);

    cout << r.length << " " << r.breadth << '\n';
    return 0;
}
*/

// ------------------------------ Call By Address ---------------------------
/*
void fun(struct Rectangle *r1)
{
    r1->length = 20;
    cout << "Length: " << r1->length << ", Breadth: " << r1->breadth << '\n';
}

int main()
{
    struct Rectangle r = {10, 5};
    fun(&r);

    cout << r.length << " " << r.breadth << '\n';
    return 0;
}
*/

// ------------------------------ Call By Reference --------------------------
/*
void fun(struct Rectangle &r1)
{
    r1.length = 20;
    cout << "Length: " << r1.length << ", Breadth: " << r1.breadth << '\n';
}

int main()
{
    struct Rectangle r = {10, 5};
    fun(r);

    cout << r.length << " " << r.breadth << '\n';
    return 0;
}
*/

// --------------------- Returing a pointer of a structure ---------------------
struct Rectangle *fun()
{
    struct Rectangle *p;
    p = new Rectangle;

    p->length = 100;
    p->breadth = 150;

    return p;
}

int main()
{
    struct Rectangle *ptr;
    ptr = fun();

    cout << ptr->length << " " << ptr->breadth << '\n';

    return 0;
}