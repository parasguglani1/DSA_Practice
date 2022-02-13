#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[100];
    int n = 25;
    // *initalize
    for (int i = 0; i < n; i++)
    {
        a[i] = 2*i;
    }

    /*
        *append
        a[5] = 6;
        int n=5;

      *insert
        int index = 3;
        for (int i = n; i > index; i--)
        {
            a[i] = a[i - 1];
        }
        a[index] = 69;
        n++;




        *delete

        int index1 = 4;
        int x = a[index1];
        for(int i =index1; i<n;i++)
        {
            a[i]=a[i+1];
        }
        n--;

         *linear search
        int key = 85;
        int i,flag=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==key)
            {
                cout<<key<<" found ";
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            cout<<key<<" Not found ";
        }

       // *binary search

    int key= 22;
    int low=0;
    int high=n-1;
    bool flag=false;
    int mid;
        while(low<high)
        {
            mid =floor((low+high)/2);
            // cout<<"mid is "<<mid<<endl;
            if (a[mid]==key)
            {
                cout<<key<< " found at index "<< mid<< endl;
                flag=true;
                break;

            }
            else if(a[mid]<key)
            {
                low=mid+1;


            }
            else
            {
                high =mid-1;

            }
            //   mid=(low+high)/2;

        }
        if (!flag){
           cout<<key<< " key not found";
        }

    *sum
    int sum =0;
    for (int i = 0; i < n; i++)
    {
        sum+=a[i];
    }
    cout<<"sum is "<<sum<<endl;


    *reverse


    for (int i = 0; i < n/2; i++)
    {
        int temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;
    }

    * insert in sorted array

    
   int to_insert=23;
   int i=n-1;
   n++;
 while (to_insert<a[i])
 { 
     a[i+1]=a[i];
     i--;    
 }
 a[i+1]=to_insert;
 
 *is sorted
 
for(int i =0; i<n-2;i++)
{
    if( a[i]>a[i+1])
    {
        cout<<" not sorted";
        break;
    }

}
  */



    // display
    for (int i = 0; i < n; i++)
    {

        cout << a[i] << " ";
    }

    return 0;
}