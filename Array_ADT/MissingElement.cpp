//Student Exercise: Displaying missing elements in a sorted array
#include <iostream>
using namespace std;

int ansSize = 0;

int singleMiss(int arr[], int n)
{
    if (arr[0] == 1)
    {
        int sum = arr[n-1]*(arr[n-1]+1)/2, s = 0; 
        for(int i = 0; i < n; i++)
            s += arr[i];
        if(s != sum)
            return (sum-s);
        return 0;
    }
    return -1;
}

int* indComp(int arr[], int n)
{
    int* ans = new int[(arr[n-1] - arr[0]) - n];
    int diff = arr[0] - 0, k = 0;
    for(int i = 0; i < n; i++)
    {
        if((arr[i] - i) != diff)
        {
            while(diff != (arr[i] - i))
            {
                ans[k++] = diff+i;
                diff++;
            }
        }
    }
    ansSize = k; //answer's size
    return ans;
}

int main()
{
    unsigned int size;
    int* temp;
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
    
    cout<<"For array with a single miss, press S: ";
    char c; cin>>c;
    if(c == 'S')
    {
        if(arr[0] == 1)
            cout<<"The missing element is: "<<singleMiss(arr, size)<<"\n";
        else
        {
            temp = indComp(arr, size);
            cout<<"The missing element is: "<<temp[0]<<"\n";
        }
    }
    else
    {
        temp = indComp(arr, size);
        cout<<"The missing elements are: ";
        for(int i = 0; i < ansSize; i++)
            cout<<temp[i]<<" ";
    }

    delete []temp;
    return 0;
}