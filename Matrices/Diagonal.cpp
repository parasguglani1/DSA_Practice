// C++ equivalent of the last program
// Implementing a 2D diagonal matrix using a structure in C
#include <iostream>
#include <limits.h>
using namespace std;

class DiagMat
{
private:
    int n;
    int filled_element;
    int *arr;

public:
    DiagMat(int n = 0)
    {
        if (n > 0)
            this->n = n;
        else
            this->n = 5; // default size
        arr = new int[this->n];
    }
    ~DiagMat();
    void set(int i, int j, int x);
    int get(int i, int j);
    friend ostream &operator<<(ostream &, DiagMat &);
    int getFilled();
};

DiagMat::~DiagMat()
{
    delete[] arr;
    n = 0;
    filled_element = 0;
}

void DiagMat::set(int i, int j, int x)
{
    if (i == j && i > 0 && j > 0 && i <= n && j <= n)
    {
        arr[i - 1] = x;
        cout << i << "th column in the " << j << "th row was set as " << x << "\n";
        filled_element++;
    }
    else
    {
        if (i != j && i > 0 && j > 0 && i <= n && j <= n)
            cout << i << "th column in the " << j << "th row was set as " << 0 << "\n";
        else if (i <= 0 || j <= 0)
            cout << "Invalid index, please enter positive numbers only\n";
        else if (i > n || j > n)
            cout << "Invalid index, out of bounds\n";
    }
}

int DiagMat::get(int i, int j)
{
    if (filled_element == 0)
    {
        cout << "Matrix is empty\n";
        return INT_MIN;
    }
    if (i == j && i <= n && j <= n && i >= 1 && j >= 1)
        return arr[i - 1];
    else
    {
        if (i > 0 && j > 0 && i <= n && j <= n)
            return 0;
        else
        {
            cout << "Invalid index\n";
            return INT_MIN;
        }
    }
}

ostream &operator<<(ostream &out, DiagMat &d)
{
    if (d.filled_element == 0)
        out << "Matrix is empty\n";
    else
    {
        for (int i = 1; i <= d.n; i++)
        {
            for (int j = 1; j <= d.n; j++)
                out << d.get(i, j) << " ";
            out << "\n";
        }
    }
    return out;
}

int DiagMat::getFilled()
{
    return filled_element;
}

void __init__Diag(int *n)
{
    while (true)
    {
        cout << "Enter the square matrix' dimension: ";
        cin >> *n;
        if (*n > 0)
            break;
        cout << "Invalid input, enter a positive number\n";
    }
}

int main()
{
    int n;
    __init__Diag(&n);
    DiagMat d(n);
    int choice;
    while (true)
    {
        printf("1. Enter an element in the matrix\n2. Get an element from the matrix\n");
        printf("3. Display matrix contents\n4. Exit the menu\n");
        printf("Enter your choice: ");
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int x, y, element;
            cout << "Enter the ith and jth dimension in 1-based indexing: ";
            cin >> x >> y;
            cout << "Enter the element: ";
            cin >> element;
            d.set(x, y, element);
            break;
        }
        case 2:
        {
            int x, y, element;
            cout << "Enter the ith and jth dimension in 1-based indexing: ";
            cin >> x >> y;
            element = d.get(x, y);
            if (x > 0 && y > 0 && x <= n && y <= n && d.getFilled() != 0)
                cout << "Element at " << y << "th column in " << x << "th row is: " << element << "\n";
            break;
        }
        case 3:
        {
            cout << d;
            /*
            Making ostream& operator <<(ostream&) a member instead of friend needs us to
            use the syntax: d.operator<<(cout);
            It works! Despite looking strange at first sight.
            */
            break;
        }
        case 4:
            cout << "Menu exited\n";
            break;
        default:
            cout << "Invalid choice, try again\n";
        }
        if (choice == 4)
            break;
    }
    d.~DiagMat();
    cout << "Program terminated\n";
    return 0;
}
