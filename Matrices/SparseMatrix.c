//Implementing Sparse matrices in C
#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int row;
    int col;
    int val; //data type of the matrix
};

struct Sparse
{
    int numRows;
    int numCols;
    int numNon0s;
    struct Element* arr; //pointer to heap
};

void reader(int* n, char s[])
{
    int inp;
    while(1)
    {
        printf("Enter the number of %s: ", s);
        scanf("%d", &inp);
        if(inp > 0)
            break;
        printf("Invalid input, try again\n");
    }
    *n = inp;
}

void allocator(struct Sparse* sp, int mag)
{
    if(mag == 0)
        sp->arr = (struct Element*)malloc((sp->numRows*sp->numCols)*sizeof(struct Element)); //worst-case - no zeroes
    else if(mag == -1)
        sp->arr = (struct Element*)realloc(sp->arr, sp->numNon0s*sizeof(struct Element)); //preventing wastage
    else if(mag > 0)
        sp->arr = (struct Element*)malloc(mag*sizeof(struct Element));
}

void create(struct Sparse* sp)
{
    reader(&sp->numRows, "rows");
    reader(&sp->numCols, "columns");
    //illusion of 2D array
    printf("Enter the matrix elements:\n");
    int temp, i, j; sp->numNon0s = 0;
    allocator(sp, 0);
    for(i = 0; i < sp->numRows; i++)
    {
        for(j = 0; j < sp->numCols; j++)
        {
            scanf("%d", &temp);
            if(temp != 0)
            {
                sp->arr[sp->numNon0s].col = j;
                sp->arr[sp->numNon0s].row = i;
                sp->arr[sp->numNon0s].val = temp;
                sp->numNon0s++;
            }
        }
    }
    allocator(sp, -1);
}

void display(struct Sparse sp)
{
    int i, j, tracker = 0;
    printf("The matrix is:\n");
    for(i = 0; i < sp.numRows; i++)
    {
        for(j = 0; j < sp.numCols; j++)
        {
            if(i == sp.arr[tracker].row && j == sp.arr[tracker].col)
                printf("%d ", sp.arr[tracker++].val);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

void deallocate(struct Sparse* sp)
{
    free(sp->arr);
    sp->numRows = sp->numCols = sp->numNon0s = 0;
}

struct Sparse* add(struct Sparse a, struct Sparse b)
{
    if(a.numRows == b.numRows && a.numCols == b.numCols)
    {
        struct Sparse* c = (struct Sparse*)malloc(sizeof(struct Sparse));
        c->numRows = a.numRows; c->numCols = a.numCols;
        allocator(c, a.numNon0s+b.numNon0s); c->numNon0s = 0;

        int i = 0, j = 0; 
        while(i < a.numNon0s && j < b.numNon0s)
        {
            if(a.arr[i].row < b.arr[j].row)
                c->arr[c->numNon0s++] = a.arr[i++]; //sets c->arr[ind]'s row, col and val equal to the RHS's
            else if(a.arr[i].row > b.arr[j].row)
                c->arr[c->numNon0s++] = b.arr[j++];
            else //both non-zero elements have the same row 
            {
                if(a.arr[i].col < b.arr[j].col)
                    c->arr[c->numNon0s++] = a.arr[i++];
                else if(a.arr[i].col > b.arr[j].col)
                    c->arr[c->numNon0s++] = b.arr[j++];
                else //both row and column of the non-zero elements are same
                {
                    c->arr[c->numNon0s] = a.arr[i++];
                    c->arr[c->numNon0s++].val += b.arr[j++].val;
                }
            }
        }

        //for remaining elements
        for(; i < a.numNon0s; i++)
            c->arr[c->numNon0s++] = a.arr[i];
        for(; j < b.numNon0s; j++)
            c->arr[c->numNon0s++] = b.arr[j];
        
        allocator(c, -1);
        //returning the answer
        return c;
    }
    else
    {
        printf("The two sparse matrices are not compatible for addition\n");
        return NULL;
    }
} 

int main()
{
    struct Sparse S1, S2, *S3;
    
    printf("--------Matrix 1--------\n");
    create(&S1);
    printf("--------Matrix 2--------\n");
    create(&S2);
    
    printf("--------Matrix 1--------\n");
    display(S1);
    printf("--------Matrix 2--------\n");
    display(S2);
    printf("--------Adduct--------\n");
    S3 = add(S1, S2);
    if(S3 != NULL)
        display(*S3);

    deallocate(&S1);
    deallocate(&S2);
    
    if(S3 != NULL)
    {
        deallocate(S3);
        free(S3);
    }

    printf("Program terminated\n");
    return 0;
}
