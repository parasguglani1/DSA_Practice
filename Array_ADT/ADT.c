#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Arr
{
    int* ptr;
    int length;
    int size;
};

void initialize(struct Arr* x)
{
    while(1)
    {
        printf("Enter the size of the array: ");
        scanf("%d", &x->size);
        if(x->size > 0)
            break;
        printf("Invalid input, try again\n");
    }
    x->ptr = (int*)malloc(x->size*sizeof(int));
    x->length = 0;
}

void extend(struct Arr* x)
{//Not intended to be used in main()
    if(x->length == x->size)
    {//to extend the array when it gets full
        x->ptr = (int*)realloc(x->ptr, x->size + 10);
        x->size = x->size+10;
    }
}

void append(struct Arr* x)
{
    extend(x);
    printf("Enter %dth element: ", x->length);
    scanf("%d",&x->ptr[x->length]);
    x->length++;
}

void display(struct Arr x)
{
    if(x.length == 0)
        printf("Array is empty\n");
    else
    {
        int i;
        printf("The array contents are: ");
        for(i = 0; i < x.length; i++)
            printf("%d ", x.ptr[i]);
        printf("\n");
    }
}

void insert(struct Arr* x, int pos, int element)
{
    //verification
    if(pos < 0 || pos >= x->length)
        printf("%d is an invalid position\n",pos);
    else //x->length == 0 is covered by default
    {
        extend(x); int i;
        //carry out the replacement
        for(i = x->length; i > pos; i--)
            x->ptr[i] = x->ptr[i-1]; //right shift
        x->ptr[pos] = element; //copied
        x->length++; //increased by 1
    }
}

int delete(struct Arr* x, int pos)
{
    if(pos < 0 || pos >= x->length ||x->length == 0)
    {
        //printf("%d is an invalid position\n",pos);
        //printf("Array is empty\n");
        return -1; //to signify invalidity
    }
    else
    {
        int i, del = x->ptr[pos];
        for(i = pos; i < x->length-1; i++) //no element to copy for x->ptr[length-1]
            x->ptr[i] = x->ptr[i+1];
        x->length--; //de facto vacancy
        return del;
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int lsearch(struct Arr* x, int element, char c)
{
    if(x->length == 0)
    {
        //printf("Array is empty\n");
        return -2; //empty array
    }
    else
    {
        int i;
        for(i = 0; i < x->length; i++)
        {
            if(x->ptr[i] == element)
            {
                if(c == 'T')
                    swap(&x->ptr[i], &x->ptr[i-1]);
                if(c == 'H')
                    swap(&x->ptr[i], &x->ptr[0]);
                return i;
            }
        }
        return -1;
    }
}

int bSearch(struct Arr x, int element)
{
    if(x.length == 0)
    {
        //printf("Array is empty\n");
        return -2; //empty array
    }
    else
    {
    //iterative
        int low = 0, high = x.length - 1, mid = (low+high)/2;
        while(low <= high)
        {
            mid = (low+high)/2;
            if(element == x.ptr[mid])
                return mid;
            if(element < x.ptr[mid])
                high = mid - 1;
            if(element > x.ptr[mid])
                low = mid + 1;
        }
        return -1;
    }
}

int get(struct Arr x, int index)
{
    if(index < 0 || index >= x.length || x.length == 0)
    {
        //printf("%d is an invalid position\n",index);
        //printf("Array is empty\n");
        return -1; //to signify invalidity
    }
    return x.ptr[index];
}

int set(struct Arr* x, int index, int element)
{
    if(index < 0 || index >= x->length || x->length == 0)
    {
        //printf("%d is an invalid position\n",index);
        //printf("Array is empty\n");
        return -1; //to signify invalidity
    }
    else
    {
        int curr = x->ptr[index];
        x->ptr[index] = element;
        return curr;
    }
}

int max(struct Arr x)
{
    if(x.length == 0)
        return -1;
    int i, max = INT_MIN;
    for(i = 0; i < x.length; i++)
        if(x.ptr[i] > max)
            max = x.ptr[i];
    return max;
}

int min(struct Arr x)
{
    if(x.length == 0)
        return -1;
    int i, min = INT_MAX;
    for(i = 0; i < x.length; i++)
        if(x.ptr[i] < min)
            min = x.ptr[i];
    return min;
}

int sum(struct Arr x)
{
    if(x.length == 0)
        return INT_MIN;
    int ans = 0, i;
    for(i = 0; i < x.length; i++)
        ans += x.ptr[i];
    return ans;
}

//recursive implementation
int rSum(struct Arr x, int index)
{
    if(x.length == 0)
        return INT_MIN;
    if(index < 0)
        return 0;
    else
        return x.ptr[index]+rSum(x, index-1);
}

float average(struct Arr x)
{
    if(x.length != 0)
        return ((float)sum(x)/x.length);
    return INT_MIN/1.0;
}

void reverse(struct Arr* x)
{
    if(x->length == 0)
        printf("Array is empty\n");
    else
    {
        int i, j, temp;
        for(i = 0, j = x->length - 1; i < j; i++, j--)
        {
            temp = x->ptr[i];
            x->ptr[i] = x->ptr[j];
            x->ptr[j] = temp;
        }
    }
}

void auxRev(struct Arr* x)
{
    if(x->length == 0)
        printf("Array is empty\n");
    else
    {
        int* ptr = (int*)malloc(x->length*sizeof(int));
        int i, j;
        for(i = x->length - 1, j = 0; i >= 0; i--, j++)
            ptr[j] = x->ptr[i];
        for(i = 0; i < x->length; i++)
            x->ptr[i] = ptr[i];
    }
}

void lShift(struct Arr* x)
{
    if(x->length == 0)
        printf("Array is empty\n");
    else
    {
        int i;
        for(i = 0; i < x->length - 1; i++)
            x->ptr[i] = x->ptr[i+1];
        x->ptr[x->length - 1] = 0;
    }
}

void lRotate(struct Arr* x)
{
    if(x->length == 0)
        printf("Array is empty\n");
    else
    {
        int i, ind0 = x->ptr[0];
        for(i = 0; i < x->length - 1; i++)
            x->ptr[i] = x->ptr[i+1];
        x->ptr[x->length - 1] = ind0;
    }
}

void rShift(struct Arr* x)
{
    if(x->length == 0)
        printf("Array is empty\n");
    else
    {
        int i;
        for(i = x->length - 1; i > 0; i--)
            x->ptr[i] = x->ptr[i-1];
        x->ptr[0] = 0;
    }
}

void rRotate(struct Arr* x)
{
    if(x->length == 0)
        printf("Array is empty\n");
    else
    {
        int i, indL = x->ptr[x->length - 1];
        for(i = x->length - 1; i > 0; i--)
            x->ptr[i] = x->ptr[i-1];
        x->ptr[0] = indL;
    }
}
//handler TO BE used by main()
void ShiftRotate(void (*func)(struct Arr*), int numShifts, struct Arr* x)
{
    if(x->length == 0)
        printf("Array is empty\n");
    else
    {
        int i;
        for(i = 1; i <= numShifts; i++)
            func(x);
    }
}

void insertSorted(struct Arr* x, int toInsert)
{
    if(x->length == 0)
        printf("Array is empty\n");
    else
    {
        extend(x);
        int i = x->length - 1;
        while(toInsert < x->ptr[i] && i >= 0)
        {
            x->ptr[i+1] = x->ptr[i];
            i--;
        }
        x->length++; //must hold for every case
        x->ptr[i+1] = toInsert;
    }
}

int isSorted(struct Arr x)
{
    if(x.length == 0)
    {
        //printf("Array is empty\n");
        return -1; //error
    }
    int i = 0, f = 0; //struct Arr rev = x; - not a deep copy
    while(x.ptr[i] == x.ptr[i+1]){i++;}
    if(x.ptr[i] > x.ptr[i+1]) //descending order
    {
        f = 1;
        reverse(&x);
    }
    for(i = 0; i < x.length - 1; i++)
    {
        if(x.ptr[i] > x.ptr[i+1])
        {
            if(f)
                reverse(&x);
            return 0;
        }
    }
    return 1;
}

void negLeft(struct Arr* x)
{
    if(x->length == 0)
    {
        printf("Array is empty\n");
        return;
    }
    int i = 0, j = x->length - 1;
    while(i < j)
    {
        while(x->ptr[i] < 0){i++;}
        while(x->ptr[j] >= 0){j--;}
        if(i < j)
            swap(&x->ptr[i], &x->ptr[j]);
    }
}

struct Arr* mergeSorted(struct Arr a, struct Arr b)
{
    int i, j, k; i = j = k = 0;
    struct Arr* c = (struct Arr*)malloc(sizeof(struct Arr));
    c->size = a.size + b.size;

    while(i < a.length && j < b.length)
    {
        if(a.ptr[i] < b.ptr[j])
            c->ptr[k++] = a.ptr[i++];
        else
            c->ptr[k++] = b.ptr[j++];
    }
    for(; i < a.length; i++)
        c->ptr[k++] = a.ptr[i];
    for(; j < b.length; j++)
        c->ptr[k++] = b.ptr[j];

    c->length = k;
    return c;
}

struct Arr* Union(struct Arr a, struct Arr b)
{
    int i, j, k; i = j = k = 0;
    struct Arr* c = (struct Arr*)malloc(sizeof(struct Arr));
    c->size = a.size + b.size;

    if(isSorted(a) && isSorted(b)) //mergeSorted-like
    {
        while(i < a.length && j < b.length)
        {
            if(a.ptr[i] < b.ptr[j])
                c->ptr[k++] = a.ptr[i++];
            else if(b.ptr[j] < a.ptr[i])
                c->ptr[k++] = b.ptr[j++];
            else
            {
                c->ptr[k++] = b.ptr[j++]; //can choose either one of a.ptr[i] and b.ptr[j]
                i++; //single copy
            }
        }
        for(; i < a.length; i++)
            c->ptr[k++] = a.ptr[i];
        for(; j < b.length; j++)
            c->ptr[k++] = b.ptr[j];
    }
    else //naïve implementation
    {
        for(; i < a.length; i++)
            c->ptr[k++] = a.ptr[i]; //copy everything from first array

        for(; j < b.length; j++)
        {
            if(lsearch(&a, b.ptr[j], 'X') == -1) //copy only if dissimilar
                c->ptr[k++] = b.ptr[j];
        }
    }
    c->length = k;
    return c;
}

struct Arr* Intersection(struct Arr a, struct Arr b)
{
    int i, j, k; i = j = k = 0;
    struct Arr* c = (struct Arr*)malloc(sizeof(struct Arr));
    c->size = a.size + b.size;

    if(isSorted(a) && isSorted(b)) //mergeSorted-like
    {
        while(i < a.length && j < b.length)
        {
            if(a.ptr[i] < b.ptr[j])
                i++;
            else if(b.ptr[j] < a.ptr[i])
                j++;
            else
            {
                c->ptr[k++] = b.ptr[j++]; //can choose either one of a.ptr[i] and b.ptr[j]
                i++; //single copy
            }
        }
        //No remnants to be copied
    }
    else //naïve implementation
    {
        for(; i < a.length; i++)
            if(lsearch(&b, a.ptr[i], 'X') != -1) //if found in second array, copy
                c->ptr[k++] = a.ptr[i];
    }
    c->length = k;
    return c;
}

struct Arr* Difference(struct Arr a, struct Arr b)
{
    int i, j, k; i = j = k = 0;
    struct Arr* c = (struct Arr*)malloc(sizeof(struct Arr));
    c->size = a.size + b.size;

    if(isSorted(a) && isSorted(b)) //mergeSorted-like
    {
        while(i < a.length && j < b.length)
        {
            if(a.ptr[i] < b.ptr[j]) //copy only from first
                c->ptr[k++] = a.ptr[i++];
            else if(b.ptr[j] < a.ptr[i])
                j++; //leave the second one as it is
            else
            {//equal elements need to be disregarded
                i++;
                j++;
            }
        }
        for(; i < a.length; i++)
            c->ptr[k++] = a.ptr[i];
        //remnants from second array not needed
    }
    else //naïve implementation
    {
        for(; i < a.length; i++)
            if(lsearch(&b, a.ptr[i], 'X') == -1) //if not found in second array, copy
                c->ptr[k++] = a.ptr[i];
    }
    c->length = k;
    return c;
}


void initializer(struct Arr* x)
{//integrated initialiazation
    if(x->length == 0)
        initialize(x);
    int i, n;
    while(1)
    {//checking for invalid inputs
        printf("Enter the number of elements you want to enter: ");
        scanf(" %d", &n); //consumes newline from previous iteration
        if(n >= 0)
            break;
        printf("Invalid input, try again with a whole number\n");
    }
    for(i = 0; i < n; i++)
        append(x);
}

void freer(struct Arr* x)
{
    free(x->ptr);
    free(x);
}

int main()
{
    struct Arr* A = (struct Arr*)malloc(sizeof(struct Arr)); A->length = 0;
    int n, i, choice;
    //initialize(A);
    printf("List of array operations:\n");
    printf("\t1. Enter one or more new elements\n\t2. Insert an element at desired index\n");
    printf("\t3. Search for an element with a key\n\t4. Delete an element\n\t5. Get/Replace the element at desired index\n");
    printf("\t6. Obtain the largest/smallest element of the array\n\t7. Obtain the sum/average of all elements\n");
    printf("\t8. Reverse the array\n\t9. Shift/rotate the array\n\t10. Insert an element in a sorted list\n");
    printf("\t11. Check if the array is sorted\n\t12. Shift all negative elements to the left of the array\n");
    printf("\t13. Merge two sorted arrays into one\n\t14. Undertake set operations\n");
    printf("\t100. Display the array\n\t0. Quit the menu\n");
    printf("---------------------------------------\n");
    while(1)
    {
        printf("Enter your choice: "); scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                //to input elements to the array
                initializer(A);
                break;
            case 2:
            {
                //input position and element
                int pos, element;
                while(1)
                {
                    if(A->length == 0)
                    {
                        printf("Array is empty, enter the first element\n");
                        pos = 0;
                        break;
                    }
                    else
                    {
                        printf("Enter the position for insertion: ");
                        scanf("%d", &pos);

                        if(pos == A->length) //a corner case
                            printf("New element will be appended to the end\n");

                        if(pos <= A->length && pos >= 0)
                            break;

                        printf("Invalid input, enter a position between 0 and %d\n", A->length);
                    }
                }
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                insert(A, pos, element);

                //validation
                printf("'%d' has been inserted at %dth position\n", A->ptr[pos], pos);
                break;
            }
            case 3:
            {
                if(A->length == 0)
                    printf("Invalid request, array is empty\n");
                else
                {
                    int key, index; char choice, c;
                    while(1)
                    {
                        printf("Enter L for linear search and B for binary search: ");
                        scanf(" %c", &choice);
                        if(choice == 'L' || choice == 'B')
                            break;
                        printf("Invalid input, try again\n");
                    }
                    //for improving linear search's effectiveness
                    if(choice == 'L')
                    {
                        printf("Press T for 'transposition' or H for 'move to head': ");
                        scanf(" %c", &c);
                    }
                    printf("Enter the key to be searched: ");
                    scanf("%d", &key);

                    if(choice == 'B' && !isSorted(*A))
                    {
                        printf("Cannot undertake binary search on unsorted array; choice is being changed\n");
                        choice = 'L';
                    }
                    index = (choice == 'L') ? lsearch(A,key, c) : bSearch(*A, key);

                    if(index == -1)
                        printf("%d is not a part of the array\n", key);
                    else
                        printf("'%d' has been found at %dth index\n", key, index);
                }
                break;
            }
            case 4:
            {
                if(A->length == 0)
                    printf("Invalid request, array is empty\n");
                else
                {
                    int pos;
                    while(1)
                    {
                        printf("Enter the position for deletion: ");
                        scanf("%d", &pos);

                        if(pos < A->length && pos >= 0)
                            break;

                        printf("Invalid input, enter a position between 0 and %d\n", A->length-1);
                    }
                    //crashes when used inside as printf("%d",delete(struct Arr*, int)) - BOGUS
                    printf("Deleted element '%d' at position: %d\n", delete(A, pos), pos);
                }
                break;
            }
            case 5:
            {
                if(A->length == 0)
                    printf("Invalid request, array is empty\n");
                else
                {
                    char c; int pos;
                    while(1)
                    {
                        printf("Enter G to get and R to replace an element: ");
                        scanf(" %c", &c);
                        if(c == 'G' || c == 'R')
                            break;
                        printf("Invalid input, try again\n");
                    }
                    while(1)
                    {
                        if(c == 'G')
                            printf("Enter the index for which the element is sought: ");
                        else
                            printf("Enter the index at which the element is to be replaced: ");

                        scanf("%d", &pos);
                        if(pos >= 0 && pos < A->length)
                            break;
                        printf("Invalid input, enter an index between 0 and %d\n", A->length-1);
                    }
                    if(c == 'G')
                        printf("Element at index %d is '%d'\n", pos, get(*A, pos));
                    else
                    {
                        int toSet;
                        printf("Enter the new element: ");
                        scanf("%d", &toSet);
                        toSet = set(A, pos, toSet); //can't replace in printf since format specifiers re evaluated right-to-left
                        printf("'%d' was replaced with '%d' at index %d\n", toSet, A->ptr[pos], pos);
                    }
                }
                break;
            }
            case 6:
            {
                if(A->length == 0)
                    printf("Invalid request, array is empty\n");
                else
                {
                    char c;
                    while(1)
                    {
                        printf("Press L for obtaining largest, S for obtaining smallest number: ");
                        scanf(" %c", &c);
                        if(c == 'L' || c == 'S')
                            break;
                        printf("Invalid input, try again\n");
                    }
                    if(c == 'L')
                        printf("'%d' is the largest element, its index is %d\n", (c == 'L')?max(*A):min(*A), lsearch(A, (c == 'L')?max(*A):min(*A), 'X'));
                    else
                        printf("'%d' is the smallest element, its index is %d\n", (c == 'L')?max(*A):min(*A), lsearch(A, (c == 'L')?max(*A):min(*A), 'X'));
                }
                break;
            }
            case 7:
            {
                if(A->length == 0)
                    printf("Invalid request, array is empty\n");
                else
                {
                    char choice, c;
                    while(1)
                    {
                        printf("Press S for obtaining the sum, A for obtaining the average of array elements: ");
                        scanf(" %c", &c);
                        if(c == 'S' || c == 'A')
                            break;
                        printf("Invalid input, try again\n");
                    }
                    if(c == 'S')
                    {
                        while(1)
                        {
                            printf("Press R for recursive sum, I for iterative sum: ");
                            scanf(" %c", &choice);
                            if(choice == 'R' || choice == 'I')
                                break;
                            printf("Invalid choice, try again\n");
                        }
                        printf("Sum of all array elements is %d\n", (choice == 'I')?sum(*A):rSum(*A, A->length - 1));
                    }
                    else
                        printf("Average of all array elements is %f\n", average(*A));
                }
                break;
            }
            case 8:
            {
                if(A->length == 0)
                    printf("Invalid request, array is empty\n");
                else
                {
                    char choice;
                    while(1)
                    {
                        printf("Enter A for auxilliary reversal, E for efficient reversal: ");
                        scanf(" %c", &choice);
                        if(choice == 'A' || choice == 'E')
                            break;
                        printf("Invalid input, try again\n");
                    }
                    (choice == 'A')?auxRev(A):reverse(A);
                    printf("Array has been reversed successfully\n");
                }
                break;
            }
            case 9:
            {
                if(A->length == 0)
                    printf("Invalid request, array is empty\n");
                else
                {
                    char choice; int numShifts;
                    while(1)
                    {
                        printf("Press R to rotate, S to shift: ");
                        scanf(" %c", &choice);
                        if(choice == 'R' || choice == 'S')
                            break;
                        printf("Invalid input, try again\n");
                    }
                    if(choice == 'R')
                    {
                        printf("N.B.: A negative step denotes leftward rotation\n");
                        while(1)
                        {
                            printf("Enter the rotation step: ");
                            scanf("%d", &numShifts);
                            if(numShifts != 0)
                                break;
                            printf("Invalid input, enter a non-zero integer\n");
                        }
                        (numShifts < 0)?ShiftRotate(lRotate, -numShifts, A):ShiftRotate(rRotate, numShifts, A);
                        printf("Array has been rotated successfully\n");
                    }
                    else
                    {
                        printf("N.B.: A negative step denotes leftward shift\n");
                        while(1)
                        {
                            printf("Enter the shift step: ");
                            scanf("%d", &numShifts);
                            if(numShifts != 0)
                                break;
                            printf("Invalid input, enter a non-zero integer\n");
                        }
                        (numShifts < 0)?ShiftRotate(lShift, -numShifts, A):ShiftRotate(rShift, numShifts, A);
                        printf("Array has been shifted successfully\n");
                    }
                }
                break;
            }
            case 10:
            {
                if(A->length == 0)
                    printf("Invalid request, array is empty\n");
                else
                {
                    if(isSorted(*A))
                    {
                        int element, pos;
                        printf("Enter the number to be inserted: ");
                        scanf("%d", &element);
                        insertSorted(A, element);
                        pos = bSearch(*A, element);
                        while(A->ptr[pos] == element){pos++;}
                        printf("'%d' was successfully inserted at index %d\n", element, pos);
                    }
                    else
                        printf("Array is not sorted\n");
                }
                break;
            }
            case 11:
            {
                if(A->length == 0)
                    printf("Invalid request, array is empty\n");
                else
                {
                    if(isSorted(*A))
                        printf("Array is sorted\n");
                    else
                        printf("Array is not sorted\n");
                }
                break;
            }
            case 12:
            {
                if(A->length == 0)
                    printf("Invalid request, array is empty\n");
                else
                {
                    negLeft(A);
                    printf("Operation executed successfully\n");
                }
                break;
            }
            case 13:
            {
                if(A->length == 0)
                    printf("Invalid request, first array is empty\n");
                else
                {
                    struct Arr* B = (struct Arr*)malloc(sizeof(struct Arr)); B->length = 0;
                    if(isSorted(*A))
                    {
                        //struct Arr *C = (struct Arr*)malloc(sizeof(struct Arr)); //can initialize here or outside
                        //can even use struct Arr *C;
                        initializer(B);
                        if(isSorted(*B))
                        {
                            printf("First array: "); display(*A);
                            printf("Second array: "); display(*B);
                            printf("Merged array: "); display(*mergeSorted(*A, *B)); //can also use display(*mergeSorted(*A, *B))
                        }
                        else
                            printf("Operation is invalid for unsorted arrays\n");
                        freer(B);
                    }
                    else
                        printf("Operation is invalid for unsorted arrays\n");
                }
                break;
            }
            case 14:
            {
                if(A->length == 0)
                    printf("Invalid request, first array is empty\n");
                else
                {
                    struct Arr* B = (struct Arr*)malloc(sizeof(struct Arr)); B->length = 0;
                    char c; int var, var1;
                    initializer(B); //initialized
                    while(1)
                    {
                        printf("Enter U for union, I for intersection, D for difference and S for verifying set membership: ");
                        scanf(" %c", &c);
                        if(c == 'U' || c == 'I' || c == 'D' || c == 'S')
                            break;
                        printf("Invalid input, try again\n");
                    }
                    if(c != 'S')
                    {
                        if(c == 'D') //A-B or B-A?
                        {
                            printf("Enter 0 to use the first array as minuend: ");
                            scanf("%d", &i);
                            if(i != 0)
                                printf("You have chosen second array as the minuend\n");
                        }
                        printf("A: "); display(*A);
                        printf("B: "); display(*B);
                        //printing paradigm
                        if(c == 'U')
                        {
                            printf("Union: ");
                            display(*Union(*A, *B));
                        }
                        else if (c == 'I')
                        {
                            printf("Intersection: ");
                            display(*Intersection(*A, *B));
                        }
                        else
                        {
                            if(i == 0)
                            {
                                printf("(A - B): ");
                                display(*Difference(*A,*B));
                            }
                            else
                            {
                                printf("(B - A): ");
                                display(*Difference(*B, *A));
                            }
                        }
                    }
                    else
                    {
                        while(1)
                        {
                            printf("Press 1 to search the first set or 2 to do so for the second one: ");
                            scanf("%d", &i);
                            if(i == 1 || i == 2)
                                break;
                            printf("Invalid entry, try again\n");
                        }
                        printf("Enter a member to be searched: ");
                        scanf("%d", &var1);

                        var = (i == 1)?lsearch(A, var1, 'X'):lsearch(B, var1, 'X');
                        if(var == -1)
                            printf("%d is not a member of the set\n", var1);
                        else
                            printf("%d is the %dth element of the set\n", var1, var);
                    }
                    freer(B);
                }
                break;
            }
            case 100:
                if(A->length == 0)
                    printf("Invalid request, array is empty\n");
                else
                    display(*A);
                break;
            case 0:
                printf("Program terminated\n");
                break;
            default:
                printf("Invalid choice, try again\n");
        }
        printf("---------------------------------------\n");
        if(choice == 0)
            break;
        else
            printf("Scroll up to refer to the options\n");
    }
    freer(A);
    return 0;
}
