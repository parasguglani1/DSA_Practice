#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The menu includes all operations upon arrays

struct Array
{
    int *A;
    int size;
    int length;
};

// Displays the entire array
void display(struct Array arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

// Inserts a new item at a given index that already contains a value
void insert(struct Array *arr, int index, int item)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = item;
        arr->length++;
    }
}

// Deletes item at a given index
int delete_item(struct Array *arr, int index)
{
    int x = 0;
    int i;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for(i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

// Searches a unique element (key) in the array and returns its index
int linear_search(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

/* Searches a unique element (key) in the array and returns its index
The array must be sorted */
int binary_search(struct Array arr, int key)
{
    int middle;
    int lower = 0;
    int higher = arr.length - 1;
    while (lower <= higher)
    {
        middle = (lower + higher) / 2;
        if (arr.A[middle] == key)
        {
            return middle;
        }
        else if (key < arr.A[middle])
        {
            higher = middle - 1;
        }
        else
        {
            lower = middle + 1;
        }
    }
    return -1;
}

// Sums all elements
int sum(struct Array arr)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
    {
        total += arr.A[i];
    }
    return total;
}

// Appends an element next to the last value in the array
void append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

// Helper function that swaps elements
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Get: retrieves an element at the given index
int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

// Set: replaces a value at a particular index
void set(struct Array *arr, int index, int new_value)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = new_value;
    }
}

// Max: finds the highest number among the elements
int max(struct Array arr) // f(n)=2n+1 -> O(n)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

// Min: finds the smallest number among the elements
int min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

// Average: Sum of all elements divided by the number of elements
float average(struct Array arr, int length)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
    {
        total += arr.A[i];
    }
    // Average can be even simpler: return sum(arr)/arr.length
    return (float) total / length;
}

// Reverse: one of the methods use an auxiliary array, O(n)
void reverse(struct Array *arr)
{
    int *B;
    B = (int *)malloc(arr->length * sizeof(int));
    for (int i = 0, j = arr->length - 1; i < arr->length; i++, j--)
    {
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
    return arr;
}

// Reverse: this other method is by swapping the elements
void reverse_swap(struct Array *arr)
{
    int temp;
    for (int i = 0, j = arr->length - 1; i < arr->length; i++, j--)
    {
        if (i > j)
        {
            break;
        }
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
    return arr;
};

void insert_sort(struct Array *arr, int key)
{
    if (arr->length == arr->size) // There needs to be at least one vacant space
    {
        return;
    }
    // While loop is useful when you don't know how many times to iterate
    int i = arr->length - 1;
    while (i >= 0 && arr->A[i] > key)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = key;
    arr->length++;
}

bool is_sorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return false;
        }
    }
    return true;
}

// Rearrange: negative numbers on the left side and positive on the right
void neg_left_side(struct Array *arr) // O(n)
{
   int i = 0;
   int j = arr->length;
   while (i < j)
   {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
   }
}

struct Array * merge(struct Array *arr1, struct Array *arr2) // Theta(m+n)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

// Union: new array with all the elements from A and B, but without duplicates
struct Array * union_sorted(struct Array *arr1, struct Array *arr2) // For sorted arrays
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

// Intersection: the third array contains elements that are shared by A and B
struct Array * intersection_sorted(struct Array *arr1, struct Array *arr2) // For sorted arrays
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

// Difference: A - B, this means the third array contains elements from A that aren't in B.
struct Array * difference_sorted(struct Array *arr1, struct Array *arr2) // For sorted arrays
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}


int main(void) {

    struct Array arr1;
    int choice, item, index, sorted;

    printf("Enter the size of the array: ");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    memset(arr1.A, 0, arr1.size*sizeof(int));
    arr1.length = 0;

    do
    {
        printf("Menu\n");
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Sum\n");
        printf("6. Append\n");
        printf("7. Get\n");
        printf("8. Set\n");
        printf("9. Max\n");
        printf("10. Min\n");
        printf("11. Average\n");
        printf("12. Reverse\n");
        printf("13. Reverse Swap\n");
        printf("14. Insert Sort\n");
        printf("15. Is it sorted?\n");
        printf("16. Negative to Left\n");
        printf("17. Length\n");
        printf("18. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: display(arr1);
                break;
            case 2: printf("Enter an item and index: ");
                scanf("%d%d", &item, &index);
                insert(&arr1, index, item);
                break;
            case 3: printf("Enter an index: ");
                scanf("%d", &index);
                printf("The deleted item is %d\n", delete_item(&arr1, index));
                break;
            case 4: printf("Is the array sorted? 0: No | 1: Yes: ");
                scanf("%d", &sorted);
                if (sorted == 0)
                {
                    printf("Enter the item: ");
                    scanf("%d", &item);
                    printf("Found at index: %d\n", linear_search(arr1, item));
                }
                else
                {
                    printf("Enter the item: ");
                    scanf("%d", &item);
                    printf("Found at index: %d\n", binary_search(arr1, item));
                }
                break;
            case 5: printf("The sum is %d\n", sum(arr1));
                break;
            case 6: printf("Enter the item: ");
                scanf("%d", &item);
                append(&arr1, item);
                break;
            case 7: printf("Enter an index: ");
                scanf("%d", &index);
                printf("Got: %d\n", get(arr1, index));
                break;
            case 8: printf("Enter the item: ");
                scanf("%d", &item);
                printf("Enter an index: ");
                scanf("%d", &index);
                set(&arr1, index, item);
                break;
            case 9: printf("Max: %d\n", max(arr1));
                break;
            case 10: printf("Min: %d\n", min(arr1));
                break;
            case 11: printf("Average: %.2f\n", average(arr1, arr1.length));
                break;
            case 12: reverse(&arr1);
                break;
            case 13: reverse_swap(&arr1);
                break;
            case 14: printf("Enter the item: ");
                scanf("%d", &item);
                insert_sort(&arr1, item);
            case 15: printf("%d\n", is_sorted(arr1));
                break;
            case 16: neg_left_side(&arr1);
                break;
            case 17: printf("Length: %d\n", arr1.length);
                break;
        }
    } while (choice < 18);

    return 0;
}
