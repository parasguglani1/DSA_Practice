#include<iostream>
#include<stdlib.h>
#include<cmath>

using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    cout<<endl<<"elements are"<<endl;
    for(i=0; i<arr.length; i++){
        cout<<endl<<arr.A[i]<<endl;
    }
} 

void append(struct Array *arr, int x){
    if(arr->length == arr->size){
        cout<<endl<<"No space to enter new element in array"<<endl;
    }
    else{
        arr->A[arr->length++] = x;
    }
}

void insert(struct Array *arr, int index, int x){
    int i=0;
    if(index>=0 &&  index <= arr->length){
        for(i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index){
    int i = 0;
    int x;
    x = arr->A[index];
    if(index>=0 && index< arr->length){
        for(i = index; i<arr->length; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int linearSearch(struct Array *arr, int key){
    int i=0;
    for(i=0; i<arr->length; i++){
        if(key == arr->A[i]){
            return i;
        }
    }
    return -1;
}

int binarysearch(struct Array *arr, int x, int beg, int end){
    int mid;
    while(beg<end){
        mid = floor((beg+end)/2);
        if(arr->A[mid] == x){
            return mid;
        }
        else if(arr->A[mid] < x){
            beg = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}

int rbinarySearch(struct Array *arr, int x, int beg, int end){
    int mid;
    if(beg<end){
        mid = floor((beg+end)/2);
        if(arr->A[mid] == x)
            return mid;
        else if(arr->A[mid] < x){
            beg = mid+1;
            rbinarySearch(arr, x, beg, end);
        }
        else{
            end = mid -1;
            rbinarySearch(arr, x, beg, end);
        }
    }
    return -1;
}

int get(struct Array *arr, int index){
    if(index>=0 && index<arr->length){
        return arr->A[index];
    }
    return -1;
}

void set(struct Array *arr, int x, int index){
    if(index>=0 && index<arr->length){
        arr->A[index] = x;
    }
}

int max(struct Array *arr){
    int max = arr->A[0];
    int pos;
    for(int i=0; i<arr->length; i++){
        if(arr->A[i] > max){
            max = arr->A[i];
            pos = i;
        }
    }
    return pos;
}

int min(struct Array *arr){
    int min = arr->A[0];
    int pos;
    for(int i=0; i<arr->length; i++){
        if(arr->A[i] < min){
            min = arr->A[i];
            pos = i;
        }
    }
    return pos;
}

int Sum(struct Array *arr){
    int sum = 0;
    for(int i=0; i<arr->length; i++){
        sum = sum + arr->A[i];
    }
    return sum;
}

float avg(struct Array *arr){
    return Sum(arr)/arr->length;
}

void reverseArray(struct Array *arr, struct Array *arr1){
    arr1->A = (int *)malloc(arr->size*sizeof(int ));
    arr1->size = arr->size;
    arr1->length = arr->length;
    for(int i=0; i<arr->length; i++){
        arr1->A[arr1->length-i-1] = arr->A[i];
    }
    for(int i=0; i<arr->length; i++){
        arr->A[i] = arr1->A[i];
    }
}

//reverse array using swap
void reverseArray(struct Array *arr){
    for(int i=0; i<arr->length; i++){
        swap(&arr->A[i], &arr->A[arr->length-1]);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//insert element in sorted array
void insertelement(struct Array *arr, int x, int index){
    if(index>=0 && index<arr->size && arr->size!=arr->length){
        int i = arr->length-1;
        while(x < arr->A[i]){
            arr->A[i+1] = arr->A[i];
            i--;
        }
    }
}

//check if array is sorted
int isSort(struct Array *arr){
    for(int i=0; i<arr->length-2; i++){
        if(arr->A[i]>arr->A[i+1]){
            return false;
        }
    }
    return true;
}

//-ve on left side
void rearrange(struct Array *arr){
    int i=0;
    int j = arr->length;
    while(i<j){
        while(arr->A[i]<0){i++;}
        while(arr->A[j]>=0){j--;}
        if(i<j){
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

void mergearray(struct Array *arr, struct Array *arr1){
    struct Array arr2;
    int size1;
    int i=0, j=0,k;
    size1 = arr->length + arr1->length;
    arr2.A = (int*)malloc(size1*sizeof(int));
    for(k=0; k<size1-2; k++){
        if(arr->A[i]<=arr1->A[j]){
            arr2.A[k] = arr->A[i];
            i++;
        }
        else if(arr->A[i]>arr1->A[j])
        {
            arr2.A[k] = arr1->A[j];
            j++;
        }
    }
    for(; i<arr->size; i++){
        arr2.A[k] = arr->A[i];
        k++;
    }
    for(; j<arr1->size; j++){
       arr2.A[k] = arr->A[j];
       k++;
    }
}

//set operation union
//o(n2) time
//A[3,1,2,3,4]
//B[3,5,1,6,7]
void union1(struct Array *arr, struct Array *arr1){
    struct Array arr2;
    arr2.A = (int *)malloc(arr->size*sizeof(int));
    arr2.size = arr->size;
    int i;
    for(i=0; i<arr->length; i++){
        arr2.A[i] = arr->A[i];
    }
    arr2.length =arr->length;
    for(int j=0; j<arr1->length; j++){
        for(int k=0; k<arr2.length; k++){
            if(arr1->A[j] != arr->A[k]){
                arr2.A[i] = arr->A[k];
                arr2.length++;
            }
        }
    }
}

//o(n) using merge
void unionmerge(struct Array *arr, struct Array *arr1){
    struct Array arr2;
    arr2.A = (int *)malloc(arr->size*sizeof(int));
    arr2.size = arr->size + arr1->size;
    int i=0, j=0;
    int k=0;
    while (i<arr->length && j<arr1->length)
    {
        if(arr->A[i]<arr1->A[j]){
            arr2.A[k] = arr->A[i];
            k++;
            i++;
        }
        else if (arr1->A[j]<arr->A[i])
        {
            arr2.A[k] = arr->A[j];
            k++;
            j++;
        }
        else{
            arr2.A[k] = arr->A[i];
            i++;k++;j++;
        }
    }
    arr2.length = k;
}

//set operation intersection
void intersection(struct Array *arr, struct Array *arr1){
    struct Array arr2;
    arr2.A = (int*)malloc(arr->size*sizeof(int));
    arr2.size = arr->size + arr1->size;
    int i=0, j=0;
    int k=0;
    while (i<arr->length && j<arr1->length)
    {
        if(arr->A[i]<arr1->A[j]){
            i++;
        }
        else if (arr1->A[j]<arr->A[i])
        {
            j++;
        }
        else if(arr->A[i] == arr1->A[j]){
            arr2.A[k] = arr->A[i];
            i++;k++;j++;
        }
    }
    arr2.length = k;
}

int main(){
    struct Array arr;
    struct Array *arr1;
    int n;
    cout<<endl<<"enter the size of array"<<endl;
    cin>>arr.size;
    arr.A = (int *)malloc(arr.size*sizeof(int ));
    Display(arr);
    return 0;
}