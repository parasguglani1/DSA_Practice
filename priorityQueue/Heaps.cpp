// Implementing max-heap and min-heap in-place on integer arrays 
# include <iostream>
# include <climits>
using namespace std;

/* n = array size in all functions, unless stated otherwise */
/*
classes:
utils - Utility class that helps with:
    - swap(int&, int&) - swapping integers
    - display(int*, int) - displaying dynamic arrays
    - inpSize() - inputting a positive number, a.k.a. array size
    - initArr(int*) - initializing dynamic arrays
Heap - base class for two heap varieties
    - createHeap(int*, int) - converts entire array into a heap-representation
    - buildHeap(int*, int) - faster implementation for converting an array into a heap
    - delAll(int*, int) - deletes all heap elements from an array
    - heapSort(int*, int) - calls the above two functions
    - insert(int*, int) - shifts the heap wall rightwards
    - del(int*, int) - shifts the heap wall leftwards
    - heapify(int*, int, int) - assists buildHeap(int*, int) by swapping just the first half of elements
MaxHeap and MinHeap
    - substantiate the three functions (insert(int*, int), del(int*, int) and heapify(int*, int, int)) as per definitions
*/

class utils
{
    public:
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void display(int* a, int n)
    {
        cout << "Array elements: ";
        for(int i = 1; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
    int inpSize()
    {
        int size;
        while(true)
        {
            cout << "Enter the array size: ";
            cin >> size;
            if(size > 0)
                break;
            else
                cout << "Invalid input, retry with a positive number\n";
        }
        return size;
    }
    int* initArr(int* size)
    {
        *size = *size + 1; //0th index left
        int* arr = new int[*size];
        arr[0] = INT_MIN;
        for(int i = 1; i < *size; i++)
        {
            cout << "Enter " << i << "th element: "; 
            cin >> arr[i]; 
        }
        return arr;
    }
}Util;
class Heap
{
    protected:
    virtual void heapify(int*, int, int) = 0;
    public:
    virtual void insert(int*, int) = 0;
    virtual int del(int*, int) = 0;
    void buildHeap(int* arr, int n)
    {
        int startInd = n/2;
        for(int i = startInd; i >= 1; i--)
            heapify(arr, n, i);
    }
    void createHeap(int* a, int n)
    {
        for(int i = 2; i < n; i++)
            insert(a, i);
    }
    void delAll(int* a, int n)
    {
        for(int i = 1; i < n-1; i++)
            del(a, n-i);
    }
    void heapSort(int* a, int n)
    {
        createHeap(a, n);
        delAll(a, n);
    }
    void heapSortFast(int* a, int n)
    {
        buildHeap(a, n);
        delAll(a, n);
    }
};
class MaxHeap:public Heap
{
    protected:
    void heapify(int* arr, int n, int i)
    {
        int largest = i;
        int l = 2*i, r = l+1;
        if(l < n && arr[l] > arr[largest])
            largest = l;
        if(r < n && arr[r] > arr[largest])
            largest = r;
        if(largest != i)
        {
            Util.swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    public:
    void insert(int* a, int n)
    {
        // inserted at index n
        int i = n;
        while(i > 1 && a[i] > a[i/2])
        {
            Util.swap(a[i], a[i/2]);
            i = i/2;
        }
    }
    int del(int* a, int n)
    {
        // delete root, replace with index n
        Util.swap(a[1], a[n]);
        int i = 1, j = 2;
        while(j <= n-1) // n-1 represents index of last heap element
        {
            if(a[j+1] > a[j])
                j++;
            if(j == n) // we shan't access a[n] since it has been deleted
                j--;
            if(a[i] < a[j])
            {
                Util.swap(a[i], a[j]);
                i = j;
                j *= 2;
            }
            else
                break;
        }
        return a[n]; // is beyond the heap
    }
};
class MinHeap:public Heap
{
    protected:
    void heapify(int* arr, int n, int i)
    {
        int largest = i;
        int l = 2*i, r = l+1;
        if(l < n && arr[l] < arr[largest])
            largest = l;
        if(r < n && arr[r] < arr[largest])
            largest = r;
        if(largest != i)
        {
            Util.swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    public:
    void insert(int* a, int n)
    {
        // inserted at index n
        int i = n;
        while(i > 1 && a[i] < a[i/2])
        {
            Util.swap(a[i], a[i/2]);
            i = i/2;
        }
    }
    int del(int* a, int n)
    {
        // delete root, replace with index n
        Util.swap(a[1], a[n]);
        int i = 1, j = 2;
        while(j <= n-1) // n-1 represents index of last heap element
        {
            if(a[j+1] < a[j])
                j++;
            if(j == n) // we shan't access a[n] since it has been deleted
                j--;
            if(a[i] > a[j])
            {
                Util.swap(a[i], a[j]);
                i = j;
                j *= 2;
            }
            else
                break;
        }
        return a[n]; // is beyond the heap
    }
};

int main()
{
    MaxHeap minHeap;
    int size = Util.inpSize();
    int* arr = Util.initArr(&size);
    minHeap.heapSortFast(arr, size);
    Util.display(arr, size);
    delete arr;
    return 0;
}