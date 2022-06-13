// Sorting algorithms
#include <iostream>
using namespace std;
/*
*critertia for analysing these sorting algorithms:
    - Bubble Sort
    - Selection Sort
    - Insertion Sort
    - Merge Sort
    - Quick Sort
    - Counting Sort
    - Radix Sort
    - Bin/Bucket Sort
    - Shell Sort
    - Heap Sort already in heap


* number of comparisons:
* number of swaps:
* Adaptivity i.e already almost sorted
* stability i.e which preserves the original order of input set
* space complexity:


    */

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    void createNew(T x)
    {
        data = x;
        next = NULL;
    }
};
template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }
    void InsertEnd(int x)
    {
        if (!tail)
        {
            head = new Node<T>;
            head->createNew(x);
            tail = head;
        }
        else
        {
            tail->next = new Node<T>;
            tail->next->createNew(x);
            tail = tail->next;
        }
    }
    T DelHead()
    {
        T toDel;
        if (!head)
            return toDel;
        Node<T> *temp = head;
        head = head->next;
        toDel = temp->data;
        delete temp;
        return toDel;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
};

template <typename T>
class sorts
{
private:
    void swap(T &, T &);
    int partition(T *, int, int);
    void quickSort(T *, int, int);
    void merge(T *, int, int, int); // merges two sorted lists in the same array
    void mergeSort(T *, int, int);
    int maxEle(T *, int);
    int minEle(T *, int);
    void setZero(T *, int); // memSet equivalent
public:
    void bubbleSort(T *, int);
    void insertionSort(T *, int);
    void selectionSort(T *, int);
    void quickSort(T *arr, int n)
    {
        quickSort(arr, 0, n - 1);
    }
    void mergeSort(T *arr, int n)
    {
        mergeSort(arr, 0, n - 1);
    }
    void countSort(T *, int);  // only for int and char
    void bucketSort(T *, int); // only for int and char
    void radixSort(T *, int);  // only for positive numbers/characters
    void shellSort(T *, int);
    void display(T *, int);
};
template <typename T>
void sorts<T>::swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
void sorts<T>::bubbleSort(T *arr, int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++) // number of passes
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++) // unsorted array keeps getting smaller
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (!flag) // no swaps in the pass means the array is already sorted
            break;
    }
    /*
*keep swapping adjacent elements if they are in wrong order

* number of passes - n-1
* number of comparisons - n(n-1)/2
* max number of swaps - n(n-1)/2
* time complexity - O(n^2)
* made adaptive by using flag best case - O(n) - already sorted
* space complexity - O(1)
* stable - yes



*if want to find k largest elements perform k passes





*/
}
template <typename T>
void sorts<T>::display(T *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
template <typename T>
void sorts<T>::insertionSort(T arr[], int n)
{
    for (int i = 1; i < n; i++) // the empty cell
    {
        int j = i - 1;
        T x = arr[i];                // since arr[i] changes, we should take out the value
        while (j > -1 && arr[j] > x) // not out of range and greater
        {
            arr[j + 1] = arr[j]; // shift
            j--;
        }
        arr[j + 1] = x; // virtually empty index, for insertion
    }
    /*
* assume left side is sorted and right side is unsorted and we are inserting the element at the correct position in the sorted array
* number of passes - n-1
* number of comparisons - n(n-1)/2
* max number of swaps - n(n-1)/2
* time complexity - O(n^2)
* adaptive by nature - best case - O(n) - already sorted
* worst case - O(n^2) - reverse sorted
* space complexity - O(1)
* stable - yes
* no usefel data without completing all the passes
* better for linked list because we don't have to shift elements



*/
}
template <typename T>
void sorts<T>::selectionSort(T *arr, int n)
{
    for (int i = 0; i < n - 1; i++) // n-1 passes
    {
        int k = i;
        for (int j = i; j < n; j++) // both j and k upon i
        {
            if (arr[k] > arr[j])
                k = j;
        }
        swap(arr[i], arr[k]); // 1 swap per pass
    }
    /*
* find the smallest element and swap it with the first element and repeat the process
* number of passes - n-1
* number of comparisons - n(n-1)/2
* number of swaps - (n-1)
* time complexity - O(n^2)
* adaptive- no
* space complexity - O(1)
* stable - no



*if want to find k smallest elements perform k passes
*/
}
template <typename T>
int sorts<T>::partition(T *arr, int l, int h)
{
    // pivot = arr[h]
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < arr[h])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

template <typename T>
void sorts<T>::quickSort(T *arr, int l, int h)
{
    if (l < h)
    {
        int ind = partition(arr, l, h);
        quickSort(arr, l, ind - 1);
        quickSort(arr, ind + 1, h);
    }

    /*
* select a pivot and partition the array around it such that all elements smaller than the pivot are to the left of it and all elements greater than the pivot are to the right of it

* number of passes - n-1
* number of comparisons - n(n+1)/2
* number of swaps - (n-1)
* worst case - when partitioning is done in the starting or end of the array
* time complexity - O(n^2)
* space complexity - O(n)

* best/average case - when partitioning is done in the middle of the array
* time complexity - O(nlogn)
* space complexity - O(logn)


* stable - no
* adaptive- no


* no usefel data without completing all the passes
*/
}
template <typename T>
void sorts<T>::mergeSort(T *arr, int l, int h)
{
    // recursive merge sort
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }

    /*
* splits the array into multiple subarrays and then merges them back to form a sorted array



* time complexity - O(nlogn)
* space complexity - O(n+logn)



* stable - no
* adaptive- no


* no usefel data without completing all the passes
*/
}

template <typename T>
void sorts<T>::merge(T *arr, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int *aux = new int[high - low + 1];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            aux[k++] = arr[i++];
        if (arr[j] < arr[i])
            aux[k++] = arr[j++];
    }
    for (; i <= mid; i++)
        aux[k++] = arr[i];
    for (; j <= high; j++)
        aux[k++] = arr[j];
    for (int i = 0; i < k; i++)
        arr[low + i] = aux[i];
    delete aux;
}
template <typename T>
int sorts<T>::maxEle(T *arr, int n)
{
    T max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
template <typename T>
int sorts<T>::minEle(T *arr, int n)
{
    T min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}
template <typename T>
void sorts<T>::setZero(T *arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = 0;
}
template <typename T>
void sorts<T>::countSort(T *arr, int n)
{
    int min = minEle(arr, n);
    int cSize = maxEle(arr, n) - min + 1; // accounting for signs and reducing memory consumption
    T *count = new T[cSize];
    setZero(count, cSize);
    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;
    int i = 0, j = 0;
    while (i < cSize)
    {
        if (count[i])
        {
            arr[j++] = i + min;
            count[i]--;
        }
        else
            i++;
    }
    delete count;

    /*
* counts the amount of each element in the array and stores it in a new array and then copies the elements in the sorted array



* time complexity - O(n)
* space complexity - O(n which is max value of the array)



* stable - no
* adaptive- no

*/
}
template <typename T>
void sorts<T>::bucketSort(T *arr, int n)
// bucket sort/bin sort is a sorting technique based on the idea that the elements in the array are distributed in a range of buckets
{
    int min = minEle(arr, n), bSize = maxEle(arr, n) - min + 1;
    LinkedList<T> **bins = new LinkedList<T> *[bSize]; // just like countSort
    for (int i = 0; i < bSize; i++)
        bins[i] = NULL;
    for (int i = 0; i < n; i++)
    {
        if (!bins[arr[i] - min]) // in case no list existed before
            bins[arr[i] - min] = new LinkedList<T>;
        bins[arr[i] - min]->InsertEnd(arr[i]);
    }
    int i = 0, j = 0;
    while (j < bSize)
    {
        while (bins[j])
        {
            arr[i++] = bins[j]->DelHead(); // copying
            if (bins[j]->isEmpty())        // ensuring that the cell starts pointing to NULL again
            {
                delete bins[j];
                bins[j] = NULL;
            }
        }
        j++;
    }

    /*
* creates a new array of linked lists and then inserts the elements in the linked list in the correct position in the new array


* time complexity - O(n)
* space complexity - O(max number +n )



* stable - no
* adaptive- no


*/
}

template <typename T>
void sorts<T>::radixSort(T *arr, int n)
{
    int max = maxEle(arr, n), nDig, i, j, divisor = 1; // for number of repetitions
    LinkedList<T> **bins = new LinkedList<T> *[10];    // decimal number system - 10 digits
    for (int i = 0; i < 10; i++)
        bins[i] = NULL;
    while (max > 0) // repeats for as many times as the number of digits in the greatest number
    {
        for (int i = 0; i < n; i++)
        {
            nDig = (arr[i] / divisor) % 10; // insertion as per the nth digit from right
            if (!bins[nDig])
                bins[nDig] = new LinkedList<T>;
            bins[nDig]->InsertEnd(arr[i]);
        }
        i = j = 0;
        while (j < 10)
        {
            while (bins[j])
            {
                arr[i++] = bins[j]->DelHead(); // copying
                if (bins[j]->isEmpty())        // ensuring that the cell starts pointing to NULL again
                {
                    delete bins[j];
                    bins[j] = NULL;
                }
            }
            j++;
        }
        max /= 10;
        divisor *= 10; // enabling proper indexing
    }
    /*
* creates a new array of linked lists of size 10 and then inserts the elements in the linked list in the correct position according to the digit in the new array


* time complexity - O(dn where d is the number of digits in the greatest number)
* space complexity - O(n )



* stable - no
* adaptive- no


*/
}
template <typename T>
void sorts<T>::shellSort(T *arr, int n)
{ // mirrors insertion sort
    int j;
    for (int gap = n / 2; gap >= 1; gap /= 2) // gaps help decrease the time complexity
    {
        for (int i = gap; i < n; i++)
        {
            j = i - gap;
            T temp = arr[i];
            while (j > -1 && arr[j] > temp)
            {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = temp;
        }
    }
    /*
* uses a gap to sort the array in a similar way to insertion sort but with a gap

* no of passes = log(n)
* time complexity - O(n logn)
* space complexity - O(n )
* stable - no
* adaptive- yes


*/
}

int main()
{
    sorts<int> S;
    int a[] = {15, 36, 187, 2, 40, 326, 2, 4007, 36, 40, 47};
    int size = sizeof(a) / sizeof(a[0]);
    S.shellSort(a, size);
    S.display(a, size);
    return 0;
}