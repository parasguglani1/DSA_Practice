#include <stdio.h>
#include <stdlib.h>

struct Random
{
    int* ptr; //troublemaker
    int length;
};

void initialize(struct Random* x)
{
    while(1)
    {
        printf("Enter the array length: ");
        scanf("%d", &x->length);
        if(x->length > 0)
            break;
        printf("Invalid input, please retry\n");
    }
    x->ptr = (int*)malloc(2*x->length*sizeof(int));
    if(x->ptr == NULL)
        printf("Memory not allocated\n");
}

void input(struct Random* x)
{
    initialize(x);
    printf("Enter %d elements\n", x->length);
    int i;
    for(i = 0; i < x->length; i++)
    {
        printf("Enter %dth element: ", (i+1));
        scanf("%d", &x->ptr[i]);
    }
}

void display(struct Random x)
{
    printf("Array elements are: ");
    int i;
    for(i = 0; i < x.length; i++)
        printf("%d ", x.ptr[i]);
    printf("\n");
}

void freer(struct Random* x, int arg)
{
    free(x->ptr);
    if(arg == 0)
    free(x);
}

struct Random* mergeSorted(struct Random a, struct Random b)
{
    int i, j, k; i = j = k = 0;
    struct Random* c = (struct Random*)malloc(sizeof(struct Random));

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

int main()
{
    struct Random* A = (struct Random*)malloc(sizeof(struct Random)); 
    struct Random* B = (struct Random*)malloc(sizeof(struct Random));
    printf("------Array A-----\n");
    input(A); 
    display(*A);
    printf("------Array B-----\n");
    input(B);
    display(*B);
    printf("------Array C-----\n");
    //struct Random* C = mergeSorted(*A, *B);
    display(*mergeSorted(*A, *B));
    freer(A, 0);
    freer(B, 0);
    //freer(C, 0);
    return 0;
}