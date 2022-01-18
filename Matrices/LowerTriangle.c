//Row-major implementation of lower triangular matrix in C
#include <stdio.h>
#include <stdlib.h>

struct LowTri
{
    int* arr;
    int n; //max size
    int len; //filled
};

void initialize(struct LowTri* l)
{
     while(1)
    {
        printf("Enter the square matrix dimension: ");
        scanf("%d", &l->n);
        if(l->n > 0)
            break;
        printf("Invalid input, enter a positive number\n");
    }
    l->arr = (int*)calloc(l->n*(l->n+1)/2, sizeof(int));
    l->len = 0;
}

void dealloc(struct LowTri* l)
{
    free(l->arr);
    l->n = l->len = 0;
}

void set(struct LowTri* l, int i, int j, int x)
{
    if(i >= j && i > 0 && j > 0 && i <= l->n && j <= l->n)
    {
        l->arr[i*(i-1)/2 + (j-1)] = x;
        l->len++;
    }
    else if(i < 1 || j < 1 || i > l->n || j > l->n)
        printf("Invalid indices, please enter positive numbers less than %d\n", l->n);
}

int get(struct LowTri l, int i, int j)
{
    if(l.len == 0)
    {
        printf("Matrix is empty\n");
        return INT_MIN;
    }
    if(i >= j && i > 0 && j > 0 && i <= l.n && j <= l.n)
        return l.arr[i*(i-1)/2 + (j-1)];
    else if(i < j)
        return 0;
    else
    {
        printf("Invalid indices, please enter positive numbers less than %d\n", l.n);
        return INT_MIN;
    }
}

void display(struct LowTri l)
{
    if(l.len == 0)
    {
        printf("Matrix is empty\n");
        return;
    }
    int i, j;
    for(i = 1; i <= l.n; i++)
    {
        for(j = 1; j <= l.n; j++)
            printf("%d ", get(l, i, j));
        printf("\n");
    }
}

int main()
{
    int i, j, x; struct LowTri L;
    initialize(&L);

    printf("Enter all matrix elements:\n");
    for(i = 1; i <= L.n; i++)
    {
        for(j = 1; j <= L.n; j++)
        {
            scanf("%d", &x);
            set(&L, i, j, x);
            if(i < j && x != 0)
                printf("Note: This is a lower triangular matrix and requisite elements will be zeroed out\n");
        }
    }

    printf("Enter indices to get a custom element: ");
    scanf("%d %d", &i, &j); x = get(L, i, j);
    if(i > 0 && i <= L.n && j > 0 && j <= L.n)
        printf("Element at %dth column in the %dth row is: %d\n", j, i, x);

    printf("Matrix contents:\n");
    display(L);

    dealloc(&L);
    printf("Program terminated\n");
    return 0;
}
