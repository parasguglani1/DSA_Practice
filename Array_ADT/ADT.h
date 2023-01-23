// Converting the code into C++
/*
17:30 -  extend(), append(T), enterElements(T), display() and a minimal main()
18:52 - insert(T, int), delete(int), lSearch(T), bSearch(T), isSorted(), get(int), set(T, int), largest() and smallest()
19:19 - sum(), rSum(int) and average()
20:58 - lShift(), rShift(), lRotate(), rRotate(), ShiftRotate(int, int) and setEqual(Array<T>*)
22:09 - insertSorted(Array), negLeft(), mergeSorted(Array), Union(Array), Intersection(Array) and Difference(Array)
Removed main()
*/
#include <iostream>
using namespace std;

template <typename T>
class Array
{
private:
    T *ptr;
    unsigned int length;
    unsigned int size;
    void extend();
    void append(T);
    void swap(T *, T *);
    void lShift();
    void lRotate();
    void rShift();
    void rRotate();

public:
    Array() // default constructor
    {
        size = 5;
        ptr = new T[size];
        length = 0;
    }
    Array(int size) // param const
    {
        this->size = size;
        ptr = new T[size];
        length = 0;
    }
    ~Array() // destructor
    {
        delete[] ptr;
    }
    void enterElements(int);
    void display();
    void insert(T, int);
    T Delete(int);
    int lSearch(T);
    int bSearch(T);
    bool isSorted();
    T get(int);
    T set(T, int);
    T largest();
    T smallest();
    T sum();
    T rSum(int);
    double average();
    void reverse();
    void ShiftRotate(int, int);
    int getLength() { return length; }
    void setEqual(Array<T> *);
    void insertSorted(T);
    void negLeft();
    Array *mergeSorted(Array<T>);
    Array *Union(Array<T>);
    Array *Intersection(Array<T>);
    Array *Difference(Array<T>);
};

template <typename T>
void Array<T>::setEqual(Array<T> *A)
{
    A->size = this->size;
    A->length = this->length;
    delete[] A->ptr;
    A->ptr = new T[A->size];
    for (int i = 0; i < this->length; i++)
        A->ptr[i] = this->ptr[i];
}

template <typename T>
void Array<T>::extend()
{
    if (length == size)
    {
        cout << "Array extended\n";
        T *tempPtr = new T[size + 10]; // more size
        for (int i = 0; i < length; i++)
            tempPtr[i] = ptr[i];
        delete[] ptr;  // old one
        ptr = tempPtr; // switched
        tempPtr = nullptr;
    }
}

template <typename T>
void Array<T>::append(T n)
{
    extend();
    ptr[length] = n;
    length += 1;
}

template <typename T>
void Array<T>::enterElements(int num)
{
    if (num <= 0)
        return; // invalid input
    for (int i = 0; i < num; i++)
    {
        cout << "Enter " << length << "th element: ";
        T element;
        cin >> element;
        append(element);
    }
}

template <typename T>
void Array<T>::display()
{
    if (length == 0)
    {
        cout << "Array is empty!\n";
        return;
    }
    for (int i = 0; i < length; i++)
        cout << ptr[i] << " ";
    cout << "\n";
}

template <typename T>
void Array<T>::insert(T toAdd, int index)
{
    if (index < 0 || index >= length)
    {
        cout << "Invalid index\n";
        return;
    }
    extend();
    for (int i = length - 1; i >= index; i--)
        ptr[i + 1] = ptr[i];
    ptr[index] = toAdd;
    length++;
}

template <typename T>
T Array<T>::Delete(int index)
{
    if (index < 0 || index >= length)
    {
        cout << "Invalid index\n";
        return -1;
    }
    T deleted = ptr[index];
    for (int i = index; i < length - 1; i++)
        ptr[i] = ptr[i + 1];
    length--;
    return deleted;
}

template <typename T>
int Array<T>::lSearch(T element)
{
    if (length == 0)
    {
        cout << "Array is empty\n";
        return -2;
    }
    for (int i = 0; i < length; i++)
    {
        if (ptr[i] == element)
            return i;
    }
    return -1;
}

template <typename T>
int Array<T>::bSearch(T element)
{
    if (length == 0)
    {
        cout << "Array is empty\n";
        return -2;
    }
    if (isSorted())
    {
        int low = 0, high = length - 1, mid = (low + high) / 2;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (element == ptr[mid])
                return mid;
            else if (element < ptr[mid])
                high = mid - 1;
            else if (element > ptr[mid])
                low = mid + 1;
        }
        return -1;
    }
    else
        return -3;
}

template <typename T>
bool Array<T>::isSorted()
{
    int f1;
    int j = 0;
    while (ptr[j] == ptr[j + 1])
    {
        j++;
    }
    if (ptr[j] > ptr[j + 1])
        f1 = 0;
    else
        f1 = 1;
    for (int i = 0; i < length - 1; i++)
    {
        if (f1 == 1)
        {
            if (ptr[i] > ptr[i + 1])
                return false;
        }
        else
        {
            if (ptr[i] < ptr[i + 1])
                return false;
        }
    }
    return true;
}

template <typename T>
T Array<T>::get(int index)
{
    if (length == 0)
    {
        cout << "Array is empty\n";
        return -2;
    }
    if (index < 0 || index >= length)
    {
        cout << "Invalid index\n";
        return -1;
    }
    return ptr[index];
}

template <typename T>
T Array<T>::set(T toSet, int index)
{
    if (length == 0)
    {
        cout << "Array is empty\n";
        return -2;
    }
    if (index < 0 || index >= length)
    {
        cout << "Invalid index\n";
        return -1;
    }
    T wasHere = ptr[index];
    ptr[index] = toSet;
    return wasHere;
}

template <typename T>
T Array<T>::largest()
{
    if (length == 0)
    {
        cout << "Array is empty\n";
        return -1;
    }
    T max = ptr[0];
    for (int i = 1; i < length; i++)
    {
        if (ptr[i] > max)
            max = ptr[i];
    }
    return max;
}

template <typename T>
T Array<T>::smallest()
{
    if (length == 0)
    {
        cout << "Array is empty\n";
        return -1;
    }
    T min = ptr[0];
    for (int i = 1; i < length; i++)
    {
        if (ptr[i] < min)
            min = ptr[i];
    }
    return min;
}

template <typename T>
T Array<T>::sum()
{
    if (length == 0)
    {
        cout << "Array is empty\n";
        return -1;
    }
    T sum;
    for (int i = 0; i < length; i++)
        sum += ptr[i];
    return sum;
}

template <typename T>
T Array<T>::rSum(int index)
{
    if (length == 0)
    {
        cout << "Array is empty\n";
        return -2;
    }
    if (index < 0)
        return 0;
    return ptr[index] + rSum(index - 1);
}

template <typename T>
double Array<T>::average() // for numeric types only
{
    if (length == 0)
    {
        cout << "Array is empty\n";
        return -1;
    }
    return sum() / (double)length;
}

template <typename T>
void Array<T>::swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T>
void Array<T>::reverse()
{
    if (length == 0)
    {
        cout << "Array is empty\n";
        return;
    }
    for (int i = 0, j = length - 1; i < j; i++, j--)
        swap(&ptr[i], &ptr[j]);
}

template <typename T>
void Array<T>::lShift()
{
    for (int i = 0; i < length - 1; i++)
        ptr[i] = ptr[i + 1];
    ptr[length - 1] = 0;
}

template <typename T>
void Array<T>::lRotate()
{
    T element = ptr[0];
    for (int i = 0; i < length - 1; i++)
        ptr[i] = ptr[i + 1];
    ptr[length - 1] = element;
}

template <typename T>
void Array<T>::rShift()
{
    for (int i = length - 1; i > 0; i--)
        ptr[i] = ptr[i - 1];
    ptr[0] = 0;
}

template <typename T>
void Array<T>::rRotate()
{
    T element = ptr[length - 1];
    for (int i = length - 1; i > 0; i--)
        ptr[i] = ptr[i - 1];
    ptr[0] = element;
}

template <typename T>
void Array<T>::ShiftRotate(int choice, int magnitude)
{
    if (length == 0)
    {
        cout << "Array is empty\n";
        return;
    }
    // choice = 0 - Shift, 1 - Rotate
    if (choice == 0)
    {
        if (magnitude > 0) // Right Shift
        {
            for (int i = 0; i < magnitude; i++)
                rShift();
        }
        else // left shift
        {
            for (int i = 0; i < -magnitude; i++)
                lShift();
        }
    }
    else if (choice == 1)
    {
        if (magnitude > 0) // Right rotate
        {
            for (int i = 0; i < magnitude; i++)
                rRotate();
        }
        else // left rotate
        {
            for (int i = 0; i < -magnitude; i++)
                lRotate();
        }
    }
    else
        cout << "Invalid choice\n";
}

template <typename T>
void Array<T>::insertSorted(T element)
{
    if (length == 0)
    {
        cout << "Array is empty\n";
        return;
    }
    if (isSorted())
    {
        extend();
        int i = length - 1;
        // to cater to descending arrays
        int f = 0, j = 0;
        while (ptr[j] == ptr[j + 1])
        {
            j++;
        }
        if (ptr[j] > ptr[j + 1])
        {
            reverse(); // makes a descending array ascending
            f = 1;
        }
        while (element < ptr[i] && i >= 0)
        {
            ptr[i + 1] = ptr[i];
            i--;
        }
        length++; // must hold for every case
        ptr[i + 1] = element;
        if (f == 1)
            reverse(); // flip again
    }
    else
        cout << "Array is not sorted\n";
}

template <typename T>
void Array<T>::negLeft()
{
    if (length == 0)
    {
        cout << "Array is empty\n";
        return;
    }
    int i = 0, j = length - 1;
    while (i < j)
    {
        while (ptr[i] < 0)
        {
            i++;
        }
        while (ptr[j] >= 0)
        {
            j--;
        }
        if (i < j)
            swap(&ptr[i], &ptr[j]);
    }
}

template <typename T>
Array<T> *Array<T>::mergeSorted(Array<T> b)
{
    int i, j, k;
    i = j = k = 0;
    Array *c = new Array(size + b.size);

    while (i < length && j < b.length)
    {
        if (ptr[i] < b.ptr[j])
            c->ptr[k++] = ptr[i++];
        else
            c->ptr[k++] = b.ptr[j++];
    }
    for (; i < length; i++)
        c->ptr[k++] = ptr[i];
    for (; j < b.length; j++)
        c->ptr[k++] = b.ptr[j];

    c->length = k;
    return c;
}

template <typename T>
Array<T> *Array<T>::Union(Array b)
{
    int i, j, k;
    i = j = k = 0;
    Array *c = new Array(size + b.size);
    if (this->isSorted() && b.isSorted()) // mergeSorted-like
    {
        while (i < length && j < b.length)
        {
            if (ptr[i] < b.ptr[j])
                c->ptr[k++] = ptr[i++];
            else if (b.ptr[j] < ptr[i])
                c->ptr[k++] = b.ptr[j++];
            else
            {
                c->ptr[k++] = b.ptr[j++]; // can choose either one of a.ptr[i] and b.ptr[j]
                i++;                      // single copy
            }
        }
        for (; i < length; i++)
            c->ptr[k++] = ptr[i];
        for (; j < b.length; j++)
            c->ptr[k++] = b.ptr[j];
    }
    else // naïve implementation
    {
        for (; i < length; i++)
            c->ptr[k++] = ptr[i]; // copy everything from first array

        for (; j < b.length; j++)
        {
            if (this->lSearch(b.ptr[j]) == -1) // copy only if dissimilar
                c->ptr[k++] = b.ptr[j];
        }
    }
    c->length = k;
    return c;
}

template <typename T>
Array<T> *Array<T>::Intersection(Array b)
{
    int i, j, k;
    i = j = k = 0;
    Array<T> *c = new Array<T>(size + b.size);
    c->size = size + b.size;

    if (isSorted() && b.isSorted()) // mergeSorted-like
    {
        while (i < length && j < b.length)
        {
            if (ptr[i] < b.ptr[j])
                i++;
            else if (b.ptr[j] < ptr[i])
                j++;
            else
            {
                c->ptr[k++] = b.ptr[j++]; // can choose either one of a.ptr[i] and b.ptr[j]
                i++;                      // single copy
            }
        }
        // No remnants to be copied
    }
    else // naïve implementation
    {
        for (; i < length; i++)
            if (b.lSearch(ptr[i]) != -1) // if found in second array, copy
                c->ptr[k++] = ptr[i];
    }
    c->length = k;
    return c;
}

template <typename T>
Array<T> *Array<T>::Difference(Array b)
{
    int i, j, k;
    i = j = k = 0;
    Array *c = new Array(size + b.size);

    if (isSorted() && b.isSorted()) // mergeSorted-like
    {
        while (i < length && j < b.length)
        {
            if (ptr[i] < b.ptr[j]) // copy only from first
                c->ptr[k++] = ptr[i++];
            else if (b.ptr[j] < ptr[i])
                j++; // leave the second one as it is
            else
            { // equal elements need to be disregarded
                i++;
                j++;
            }
        }
        for (; i < length; i++)
            c->ptr[k++] = ptr[i];
        // remnants from second array not needed
    }
    else // naïve implementation
    {
        for (; i < length; i++)
            if (b.lSearch(ptr[i]) == -1) // if not found in second array, copy
                c->ptr[k++] = ptr[i];
    }
    c->length = k;
    return c;
}
