//demonstrating various kinds of 2D arrays
#include <iostream>
using namespace std;

template <class T>
void filler(T** arr, int x, int y, T seed)
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
            arr[i][j] = seed+i*y+j;
    }
}

template <class T>
void display(T** arr, int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
}

int main()
{
    //creating a two-dimensional array in heap
    char** c;
    c = new char*[4];
    for(int i = 0; i < 4; i++)
        c[i] = new char[2];
    filler(c, 4, 2, 'A');

    //creating a two-dimensional array partially in heap
    float* f[4];
    for(int i = 0; i < 4; i++)
        f[i] = new float[3];
    filler(f, 4, 3, 3.912f);

    //creating a two-dimensional array in stack
    int i[2][5] = {0}; int *a = *i;

    //filler(&a, 2, 5, -10); - doesn't work for *i, i, &i etc.
     for(int k = 0; k < 2; k++)
    {
        for(int j = 0; j < 5; j++)
            i[k][j] = -5+k*5+j;
    }

    display(c, 4, 2); cout<<"\n";
    display(f, 4, 3); cout<<"\n";
    //display(&a, 2, 5); cout<<"\n"; - doesn't work, can pass to an int* if needed
    for(int k = 0; k < 2; k++)
    {
        for(int j = 0; j < 5; j++)
            cout<<i[k][j]<<" ";
        cout<<"\n";
    }

    return 0;
}