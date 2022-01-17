//Student Exercise: Print duplicate elements of an array
#include <iostream>
using namespace std;

void duplicates(int a[], int n)
{
    int lastDuplicate = 0;
    for(int i = 0; i < n - 1; i++)
    {
        if(a[i] == a[i+1] && a[i] != lastDuplicate)
        {
            lastDuplicate = a[i];
            cout<<a[i]<<" ";
        }
    }
}

void countDuplicate(int a[], int n)
{
    int j;
    for(int i = 0; i < (n-1); i++)
    {
        if(a[i] == a[i+1])
        {
            j = i+1;
            while(a[i] == a[j])
            {
                if(j+1 != n+1) //preventing out-of-bounds 
                    j++; 
                else
                    break;
            }
            cout<<a[i]<<"\t"<<(j-i)<<"\n";
            i = j-1; //i = j leads to an element getting skipped
        }
    }
}

void hashCount(int a[], int n)
{//works for positive and negative elements
    int size = a[n-1] - a[0] + 1;
    int H[size] = {0};
    for(int i = 0; i < n; i++)
        H[a[i]-a[0]]++;
    for(int i = 0; i < size; i++)
        if(H[i] > 1)
            cout<<i+a[0]<<"\t"<<H[i]<<"\n";
}

int main()
{
    unsigned int size;
    while(1)
    {
        cout<<"Enter the array size: ";
        cin>>size;
        if(size > 0)
            break;
        cout<<"Erroneous input, try again\n";
    }
    int arr[size];
    cout<<"Enter the array elements in ascending order: ";
    for(int i = 0; i < size; i++)
        cin>>arr[i];
    
    cout<<"Duplicate elements: "; duplicates(arr, size);
    cout<<"\nElement\tFrequency\n"; countDuplicate(arr, size);
    cout<<"\nElement\tFrequency\n"; hashCount(arr, size);
    cout<<"Terminated successfully\n";
    return 0;
}