#include<stdio.h>
#include<iostream>
using namespace std;

struct Array
{
    /* data */
    // int *A;
    int A[20];
    int size = 10;
    int length;
};

void Display(struct Array arr){
    printf("\nelements \n");
    for(int i = 0;i<arr.size;i++)
        printf("%d\n",arr.A[i]);
}

void append(/*pass by address because we are changing the array and want to keep the change.*/struct Array *arr,int value){
    if(!(arr->length < arr->size)) return;
    arr->A[arr->length] = value;
    arr->length++;
}

void Insert(struct Array *arr,int index,int value){
    if(index>=0 && index<=arr->length){
        for(int i = arr->length;i>index;i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = value;
        arr->length++;
    }
}

int Delete(struct Array *arr,int index){
    int ele=0;
    if(index>=0 && index < arr->length){
        ele = arr->A[index];
        for(int i = index; i < arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
    return ele;
}
// 4/5/21
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array arr,int key){
    for(int i = 0;i<arr.length;i++){
        if(arr.A[i] == key){
            return i;
        }
    }
    return -1;
}
int TranspositionLinearSearch(struct Array *arr,int key){
    for(int i = 0;i<arr->length;i++){
        if(arr->A[i] == key){
            swap(&arr->A[i],&arr->A[i-1]);
            return i;
        }
    }
    return -1;
}
int MovetoheadLinearSearch(struct Array *arr,int key){
    for(int i = 0;i<arr->length;i++){
        if(arr->A[i] == key){
            swap(&arr->A[i],&arr->A[0]);
            return i;
        }
    }
    return -1;
}
int binarySearch(struct Array arr,int value){
    int l = 0,h = arr.length-1,mid;
    while(l<=h){
        mid = (l+h)/2;
        if(arr.A[mid] == value)return mid;
        else if(arr.A[mid] < value) l = mid + 1;
        else h = mid-1;
    }
    return -1;
}
int rbinSearch(int a[],int l,int h,int value){
    // cout<<l<<h<<value<<endl;
    if(l<=h){
        int mid = (l+h)/2;
        // cout<<mid<<endl;
        if(a[mid] == value) 
            return mid;
        else if(a[mid] < value)
            return rbinSearch(a,mid+1,h,value);
        else 
            return rbinSearch(a,l,mid-1,value);
    }
    return -1;
}
// 5/5/21
int get(struct Array arr,int idx){
    if(idx < 0  || idx >= arr.length) return -1;
    return arr.A[idx];
}
int set(struct Array *arr,int idx,int val){
    if(idx < 0  || idx >= arr->length) return -1;
    arr->A[idx] = val;
    return 1;
}
int Max(struct Array arr){
    int max = arr.A[0];
    for(int i = 0;i<arr.length;i++){
        if(arr.A[i] > max) max = arr.A[i];
    }
    return max;
}
int Min(struct Array arr){
    int min = arr.A[0];
    for(int i = 0;i<arr.length;i++){
        if(arr.A[i] < min) min = arr.A[i];
    }
    return min;
}
int Sum(struct Array arr){
    int sum = 0;
    for(int i = 0;i<arr.length;i++){
        sum += arr.A[i];
    }
    return sum;
}
int Rsum(int a[],int n){
    if(n<0)return 0;
    return Rsum(a,n-1) + a[n];
}

void Reverse1(struct Array *arr){
    int i,j;
    int *B;
    B = (int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
        B[j] = arr->A[i];
    
    for(i=0;i<arr->length;i++)
        arr->A[i] = B[i];
}
void Reverse2(struct Array *arr){
    int i = 0,j= arr->length-1;
    while(i<j){
        swap(&arr->A[i],&arr->A[j]);
        i++;
        j--;
    }
}

void leftShift(struct Array *arr){
    int val = arr->A[0];
    for(int i = 0;i<arr->length-1;i++)
        arr->A[i]=arr->A[i+1];
    arr->A[arr->length-1] = val;
}
void rightShift(struct Array *arr){
    int val = arr->A[arr->length-1];
    for(int i = arr->length-1;i>0;i--)
        arr->A[i]=arr->A[i-1];
    arr->A[0] = val;
}
//6/5/21

int checkSorted(struct Array arr){
    for(int i = 0;i<arr.length-1;i++){
        if(arr.A[i+1]<arr.A[i])return -1;
    }
    return 1;
}
void  insertSorted(struct Array *arr,int val){
    if(arr->length == arr->size) return ;
    int i = arr->length-1;
    while (i>=0 && arr->A[i] > val)
    {
        arr->A[i+1]=arr->A[i];
        i--;    
    }
    arr->A[i+1] = val;
    arr->length++;
    
}
void leftShiftnegative(struct Array *arr){
    int i = 0;
    int j = arr->length-1;
    while(i<j){
        while(arr->A[i] < 0)i++;
        while(arr->A[j] >= 0)j--;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }
}

struct Array* Merge(struct Array *arr1,struct Array *arr2){
    int i,j,k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    arr3->length = arr3->size =  arr1->length + arr2->length;
    while (i<arr1->length && j < arr2->length)
    {
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k] = arr1->A[i];
            i++;k++;
        }
        if(arr1->A[i]>=arr2->A[j]){
            arr3->A[k] = arr1->A[j];
            j++;k++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k] = arr1->A[i];
        k++;
    }
    for(;j<arr2->length;j++){
        arr3->A[k] = arr2->A[j];
        k++;
    }

    return arr3;
}
struct Array* UnionSet(struct Array *arr1,struct Array *arr2){
    int i,j,k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    while (i<arr1->length && j < arr2->length)
    {
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k] = arr1->A[i];
            i++;k++;
        }
        if(arr1->A[i]>arr2->A[j]){
            arr3->A[k] = arr2->A[j];
            j++;k++;
        }
        else{
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k] = arr1->A[i];
        k++;
    }
    for(;j<arr2->length;j++){
        arr3->A[k] = arr2->A[j];
        k++;
    }
    arr3->length = arr3->size = k;

    return arr3;
}
struct Array* intersectionSet(struct Array *arr1,struct Array *arr2){
    int i,j,k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    while (i<arr1->length && j < arr2->length)
    {
        if(arr1->A[i]<arr2->A[j]){
            i++;
        }
        if(arr1->A[i]>arr2->A[j]){
            j++;
        }
        else{
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = arr3->size = k;

    return arr3;
}
struct Array* differenceSet(struct Array *arr1,struct Array *arr2){
    int i,j,k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
    while (i<arr1->length && j < arr2->length)
    {
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }
        if(arr1->A[i]>arr2->A[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k] = arr1->A[i];
        k++;
    }

    arr3->length = arr3->size = k;

    return arr3;
}

// 8/5/21

int firstNMissing(int a[],int x){
    int n = x+1;
    // cout<<n;
    int firstNsum = (n*(n+1))/2;
    int sum  = 0;
    for(int i = 0;i<n ;i++)sum+=a[i];
    printf("missing element : %d\n",firstNsum- sum);
    return firstNsum - sum;
}

int findOneMissing(int a[],int n){
    int diff = a[0];
    for(int i = 0 ; i < n ;i++){
        if(a[i] - i != diff){
            printf("the missing element is : %d",i+diff);
            return i+diff;
        }
    }
    return -1;

}


void FindMultipleMissing(int a[],int n){
    int diff = a[0];
    for(int i = 0;i< n ;i++){
        if(a[i] - i != diff){
            while (diff != a[i]-i)
            {
                printf("missing element : %d\n",i+diff);
                diff++;
            }
            
        }
    }
} 

void findMultipleMissingHash(int a[],int n,int max){
    int h[max]={0};
    for(int i = 0 ;i< n;i++){
        h[a[i]]++;
    }
    for(int i = 1;i<max;i++){
        if(h[i] == 0)printf("missing element : %d\n",i);
    }
}

void findDuplicates(int a[],int n){
    int last;
    for(int i = 0;i<n-1;i++){
        if(a[i+1] == a[i] && a[i] != last){
            printf("duplicate : %d\n",a[i]);
            last = a[i];
        }
    }
}

void countDuplicates(int a[],int n){
    int last,count,j;
    for(int i = 0 ;i<n-1;i++){
        if(a[i] == a[i+1]){
             j = i;
            count = 0;
            while(a[j] == a[i]){
                count++,j++;
            }
        }
        printf("Duplicate element %d appear : %d times\n",a[i],count);
        i = j;
    }
}

// 9/5/21
void findDuplicateHash(int a[],int n,int max){
    int h[max] = {0};
    for(int i = 0 ;i<n;i++){
        h[a[i]]++;
    }
    for(int i = 0;i<= max;i++){
        // cout << i << " " << h[i] << endl;
        if(h[i]>1){
            cout << "element : " << i << " appears : " << h[i] << " times." <<endl;
        }
    }
}

void duplicateUnsorted(int a[],int n){
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(a[i] == a[j] && a[i] != -1){
                cout<< "Duplicate : " << a[i]<<endl;
                a[j] = -1;
            }

        }
    }
}

// min max one scan
struct  MinMax{
    int min,max;
};
struct MinMax OneScan(int a[],int n){
    int min = a[0],max = a[0];
    for(int i = 1;i<n;i++){
        if(a[i] > max)max = a[i];
        if(a[i] < min)min = a[i];
    }
    struct MinMax minmax = {min , max};
    return minmax;
}

void pairSum(int a[],int n,int val){
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(a[i] + a[j] == val){
                cout << "elements : " << a[i] << " " << a[j] << endl;
            }
        }
    }
}
void pairSumHash(int a[],int n,int max,int val){
    int h[max] = {0};
    int diff;
    for(int i = 0;i<n;i++){
        diff = val - a[i];
        if(h[diff] != 0){
            cout << diff << "+" << a[i] << " = " + val << endl;
        }
        h[a[i]]++;
    }
}

void pairSumSorted(int a[],int n,int val){
    int i = 0,j = n-1;
    while(i<j){
        if(a[i] + a[j] == val){
            printf("%d + %d = %d\n",a[i],a[j],val);
            i++;
            j--;
        }
        else if(a[i] + a[j] > val){j--;}
        else {i++;}
    }
}
int main(){
    struct Array arr = {{1,2,3,4,5},6,5};
    pairSumSorted(arr.A,arr.length,6);
    // pairSumHash(arr.A,arr.length,7,9);
    // pairSum(arr.A,arr.length,9);
    // struct MinMax minmax = OneScan(arr.A,arr.length);
    // cout << minmax.min << " " << minmax.max;
    // findDuplicateHash(arr.A,arr.length,8);
    // duplicateUnsorted(arr.A,arr.length);
    // findDuplicateHash(arr.A,arr.length,6);
    // findOneMissing(arr.A,arr.length);

    // FindMultipleMissing(arr.A,arr.length);
    // findMultipleMissingHash(arr.A,arr.length,36);
    // firstNMissing(arr.A,arr.length);
    // findDuplicates(arr.A,arr.length);
    // countDuplicates(arr.A,arr.length);
    // struct Array arr2 = {{3,6,7,15,20},6,5};

    /*
    // struct Array arr;
    // printf("enter size of array \n");
    // scanf("%d",&arr.size);

    // // printf("%d",arr.size);
    // arr.A = (int*)malloc(arr.size*sizeof(int));
    // arr.length = 0;
    // int n = 0;
    // printf("enter number of elements \n");
    // scanf("%d",&n);

    // printf("enter elements : \n");
    // for(int i = 0 ; i < n;i++) scanf("%d",&arr.A[i]);

    // arr.length = n;
    // Display(arr);
    struct Array arr = {{1,2,3,4,5},6,5};
    append(&arr,10);
    Insert(&arr,4,89);
    int del= Delete(&arr,4);
    printf("%d\n",del);
    */
   
    // printf("%d",LinearSearch(arr,32));
    // printf("%d",TranspositionLinearSearch(&arr,32));
    // printf("%d",MovetoheadLinearSearch(&arr,5));
    // printf("%d",LinearSearch(arr,40));
    // printf("%d",rbinSearch(arr.A,0,arr.length-1,65));

    // printf("%d",get(arr,2));
    // printf("%d",set(&arr,2,98));
    // printf("%d\n",Max(arr));
    // printf("%d\n",Min(arr));
    // printf("%d\n",Sum(arr));
    // printf("%d\n",Rsum(arr.A,arr.length-1));
    // Reverse2(&arr);
    // leftShift(&arr);
    // rightShift(&arr);
    // printf("%d",checkSorted(arr));
    // leftShiftnegative(&arr);
    // insertSorted(&arr,3);
    // arr3 = Merge(&arr,&arr2);
    // struct Array *arr3;
    // arr3 = differenceSet(&arr,&arr2);
// * -> pointer , ** -> dereference the pointer , i.e , pointer to a pointer is derefecing the pointer
    // Display(*arr3);

    return 0;
}

