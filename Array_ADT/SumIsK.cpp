//Student exercise to display numbers from an unsorted array that sum up to 'K' 
#include <iostream>
using namespace std;

void checkSum(int A[], int n, int k)
{//repetitions make it faulty
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(A[i]+A[j] == k) //the addend was found
                cout<<A[i]<<"+"<<A[j]<<" = "<<k<<"\n";
        }
    }
}

void hashCheck(int A[], int n, int k)
{
    int max = INT_MIN, min = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(A[i] > max)
            max = A[i];
        if(A[i] < min)
            min = A[i];
    }
    int size = max - min + 1;
    int H[size] = {0};
    //6 3 8 10 16 7 5 2 9 14
    for(int i = 0; i < n; i++)
    {
        if((k-A[i]-min) >= 0 && (k-A[i]-min) < size && H[k - A[i] -min] != 0) //the addend was found
            cout<<A[i]<<"+"<<(k-A[i])<<" = "<<k<<"\n";
        H[A[i] - min]++;
    }
}

void sortedCheck(int A[], int n, int k)
{//needs a sorted array
    int i = 0, j = n-1;
    while(i < j)
    {
        if(A[i] + A[j] > k)
            j--;
        else if(A[i] + A[j] < k)
            i++;
        else
        {
            cout<<A[i]<<"+"<<A[j]<<" = "<<k<<"\n";
            i++;
            j--;
        }
    } //more readable than for loop for this scenario
}

int main()
{
    unsigned int size;
    cout<<"Do not enter repeated elements!\n";
    while(1)
    {
        cout<<"Enter the array size: ";
        cin>>size;
        if(size > 0)
            break;
        cout<<"Erroneous input, try again\n";
    }
    int arr[size], k;
    cout<<"Enter the array elements: ";
    for(int i = 0; i < size; i++)
        cin>>arr[i];
    cout<<"Enter the sum: "; cin>>k;
    cout<<"Naive method:\n"; checkSum(arr, size, k);
    cout<<"Using hash table:\n"; hashCheck(arr, size, k);
    cout<<"Using checker for sorted array:\n"; sortedCheck(arr, size, k);
    cout<<"\nTerminated successfully\n";
    return 0;
}