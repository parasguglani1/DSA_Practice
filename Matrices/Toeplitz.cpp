// Implementation of Toeplitz matrix
#include <iostream>
using namespace std;

class Toeplitz
{
private:
    int *A;
    int n;
    int filled_element;

public:
    Toeplitz(int dimension = 0)
    {
        if (dimension > 1)
            n = dimension;
        else
            n = 3;
        A = new int[2 * n - 1];
        filled_element = 0;
    }
    ~Toeplitz()
    {
        delete[] A;
    }
    void create();
    void display();
    void set(int, int, int);
    int get(int, int);
};

void Toeplitz::create()
{
    if (filled_element == 0 && n > 0)
    {
        cout << "Enter the Toeplitz matrix elements row-by-row:\n";
        int temp;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> temp;
                if (i == 1)
                {
                    A[j - 1] = temp;
                    filled_element++;
                }
                else if (j == 1)
                {
                    A[n + (i - 2)] = temp;
                    filled_element++;
                }
            }
        }
    }
    else
        cout << "Matrix was filled before\n";
}

int Toeplitz::get(int i, int j)
{
    if (filled_element == 0)
    {
        cout << "Matrix is empty\n";
        return -1;
    }
    if (i > 0 && j > 0 && i <= n && j <= n)
    {
        int index = i - j;
        if (index <= 0)
            return A[-index];
        else
            return A[n + index - 1];
    }
    else
    {
        cout << "Invalid indices\n";
        return -1;
    }
}

void Toeplitz::set(int i, int j, int toSet)
{
    if (filled_element == 0)
    {
        cout << "Matrix is empty\n";
        return;
    }
    if (i > 0 && j > 0 && i <= n && j <= n)
    {
        int index = i - j;
        if (index <= 0)
            A[-index] = toSet;
        else
            A[n + index - 1] = toSet;
    }
    else
        cout << "Invalid indices\n";
}

void Toeplitz::display()
{
    if (filled_element != 0)
    {
        int index;
        cout << "Matrix contents are:\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                index = i - j;
                if (index <= 0)
                    cout << A[-index] << " ";
                else
                    cout << A[n + index - 1] << " ";
            }
            cout << "\n";
        }
    }
    else
        cout << "Matrix is empty!\n";
}

int main()
{
    int dimension, ch, i, j, x = 0;
    while (true)
    {
        cout << "Enter the Toeplitz square matrix dimension: ";
        cin >> dimension;
        if (dimension > 0)
            break;
        cout << "Invalid choice, retry with a positive input\n";
    }
    Toeplitz A(dimension);
    while (true)
    {
        cout << "Menu for Toeplitz matrix:\n";
        cout << "1. Fill all the matrix elements anew\n2. Get an element from the matrix\n";
        cout << "3. Replace an element in the matrix\n4. Display the matrix\n";
        cout << "0. Exit the menu\nEnter your choice: ";
        cin >> ch;
        if (x == 0 && ch != 1)
        {
            cout << "Your choice was changed to '1' since the matrix has not been initialized yet\n";
            ch = 1;
            x++;
        }
        if (ch == 1)
        {
            A.create();
            x = 1;
        }
        else if (ch == 2)
        {
            while (true)
            {
                cout << "Enter the (i, j) indices from which the element is to be retrieved: ";
                cin >> i >> j;
                if (i > 0 && j > 0 && i <= dimension && j <= dimension)
                    break;
                cout << "Invalid indices, retry with a pair of inputs between 1 and " << dimension << "\n";
            }
            cout << "Element at " << j << "th column in " << i << "th row is: " << A.get(i, j) << "\n";
        }
        else if (ch == 3)
        {
            while (true)
            {
                cout << "Enter the (i, j) indices from which the element is to be changed: ";
                cin >> i >> j;
                if (i > 0 && j > 0 && i <= dimension && j <= dimension)
                    break;
                cout << "Invalid indices, retry with a pair of inputs between 1 and " << dimension << "\n";
            }
            cout << "Enter the new element to be set: ";
            cin >> x;
            A.set(i, j, x);
            x = 1; // might have been set as zero
            cout << "Element at " << j << "th column in " << i << "th row has been set as: " << A.get(i, j) << "\n";
        }
        else if (ch == 4)
            A.display();
        else if (ch < 0 || ch > 4)
            cout << "Invalid choice, retry with numbers indicated in the menu\n";
        else if (ch == 0)
            break;
    }
    A.~Toeplitz();
    cout << "Program terminated\n";
    return 0;
}