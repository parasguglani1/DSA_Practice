//Implementing a 2D diagonal matrix using a structure in C
#include <stdio.h>
#include <stdlib.h>

struct DiagMat
{
    int n;
    int filled_element; //privy to the structure
    int* arr;
};

void allocate(struct DiagMat* d)
{
    int x, y;
    while(1)
    {
        printf("Enter the (x,y) matrix dimensions: ");
        scanf("%d %d", &x, &y);
        if(x == y && x > 0 && y > 0)
            break;
        printf("Invalid input, enter non-negative and equal dimensions\n");
    }
    d->n = x; d->filled_element = 0;
    d->arr = (int*)calloc(x, sizeof(int));
}

void deallocate(struct DiagMat* d)
{
    if(d->n != 0)
    {
        free(d->arr);
        d->n = 0;
        d->filled_element = 0;
        printf("Deallocated matrix\n");
    }
}

void set(struct DiagMat* d, int i, int j, int x)
{
    if(i == j && i > 0 && j > 0 && i <= d->n && j <= d->n)
    {
        d->arr[i-1] = x;
        printf("%dth column in the %dth row was set as %d\n", i, j, x);
        d->filled_element += 1;
    }
    else
    {
        if(i != j && i > 0 && j > 0 && i <= d->n && j <= d->n)
            printf("%dth column in the %dth row was set as 0\n", i, j);
        else if(i < 0 || j < 0)
            printf("Invalid index, please enter positive numbers only\n");
        else if(i > d->n || j > d->n)
            printf("Invalid index, out of bounds\n");
    }
}

int get(struct DiagMat d, int i, int j)
{
    if(d.filled_element == 0)
    {
        printf("Matrix is empty\n");
        return INT_MIN;
    }
    if(i == j && i <= d.n && j <= d.n)
        return d.arr[i-1];
    else
    {
        if(i > 0 && j > 0 && i <= d.n && j <= d.n)
            return 0;
        else
        {
            printf("Invalid index\n");
            return INT_MIN;
        }
    }
}

void display(struct DiagMat d)
{
    if(d.filled_element == 0)
    {
        printf("Matrix is empty\n");
        return;
    }
    int i, j;
    for(i = 1; i <= d.n; i++)
    {
        for(j = 1; j <= d.n; j++)
            printf("%d ", get(d, i, j));
        printf("\n");
    }
}

int main()
{
    struct DiagMat d;
    allocate(&d); int choice;

    while(1)
    {
        printf("1. Enter an element in the matrix\n2. Get an element from the matrix\n");
        printf("3. Display matrix contents\n4. Exit the menu\n");
        printf("Enter your choice: "); scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                int x, y, element;
                printf("Enter the ith and jth dimension in 1-based indexing: ");
                scanf("%d %d", &x, &y);
                printf("Enter the element: "); scanf("%d", &element);
                set(&d, x, y, element);
                break;                
            }
            case 2:
            {
                int x, y, element;
                printf("Enter the ith and jth dimension in 1-based indexing: ");
                scanf("%d %d", &x, &y); element = get(d, x, y);
                if(x > 0 && y > 0 && x <= d.n && y <= d.n && d.filled_element != 0)
                    printf("Element at %dth column in %dth row is: %d\n", x, y, element);
                break;
            }
            case 3:
            {
                display(d);
                break;
            }
            case 4:
                printf("Menu exited\n");
                break;
            default:
                printf("Invalid choice, try again\n");
        }
        if(choice == 4)
            break;
    }
    deallocate(&d);
    printf("Program terminated\n");

    return 0;
}