//Student Exercise to print frequency of duplicates in an unsorted array
#include <iostream>
using namespace std;

bool linSearch(int A[], int n, int* k)
{
    for(int i = 0; i < n; i++)
        if(A[i] == *k)
            return 1;
    return 0;
}

void naiveDups(int A[], int n)
{
    //creating the duplicate flag
    int flag = INT_MAX;
    if(linSearch(A, n, &flag))
    {
        flag = INT_MIN;
        if(linSearch(A, n, &flag))
        {
            flag = 0;
            while(linSearch(A, n, &flag))
                flag++;
        }
    }
    //to prevent mutation of array
    int temp[n];
    for(int i = 0; i < n; i++)
        temp[i] = A[i];
    //actual procedure
    for(int i = 0; i < n-1; i++)
    {
        int count = 1;
        if(temp[i] != flag)
        {
            for(int j = i+1; j < n; j++)
            {
                if(temp[i] == temp[j])
                {
                    temp[j] = flag;
                    count++;
                }
            }
            if(count > 1)
                cout<<temp[i]<<"\t"<<count<<"\n";
        }
    }
    cout<<"\nFlag: "<<flag<<"\n";
}

void hashDups(int a[], int n)
{
    //find max and min
    int max = INT_MIN, min = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];
    }

    int size = max - min + 1;
    int H[size] = {0};
    for(int i = 0; i < n; i++)
        H[a[i]-min]++;
    for(int i = 0; i < size; i++)
        if(H[i] > 1)
            cout<<i+min<<"\t"<<H[i]<<"\n";
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
    cout<<"Enter the array elements: ";
    for(int i = 0; i < size; i++)
        cin>>arr[i];
    
    cout<<"\nElement\tFrequency\n"; naiveDups(arr, size);
    cout<<"\nElement\tFrequency\n"; hashDups(arr, size);
    cout<<"Terminated successfully\n";
    return 0;
}