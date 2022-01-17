//Student exercise to find the minimum and maximum element in one go and outputting number of comparisons
#include <iostream>
using namespace std;

int* MaxMin(int A[], int n)
{
    int* k = new int[2];
    int minComp = 0, maxComp = 0;
    k[0] = k[1] = A[0];
    for(int i = 1; i < n; i++)
    {
        if(A[i] < k[0]) //if it passes, we do not check for max
            k[0] = A[i];
        else
        {
            maxComp++;
            if(A[i] > k[1])
                k[1] = A[i];
        }
        minComp++;
    }
    cout<<"Comparisons = "<<minComp+maxComp<<"\n";
    return k;
}

int main()
{
    int size;
    while(1)
    {
        cout<<"Enter the array size: ";
        cin>>size;
        if(size > 0)
            break;
        cout<<"Erroneous input, try again\n";
    }
    int arr[size];
    cout<<"Enter the array elements: ";
    for(int i = 0; i < size; i++)
        cin>>arr[i];
    
    int* result = MaxMin(arr, size);
    cout<<"Largest element: "<<result[0]<<"\n";
    cout<<"Smallest element: "<<result[1]<<"\n";

    return 0;
}