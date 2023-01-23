// Linked-lists in C

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};

/*insertion operations follow*/
void atEnd(struct Node **head, int n)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *tempLast = *head;
    newNode->data = n;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (tempLast->next != NULL) // using tempLast != NULL does not link the node as expected
        tempLast = tempLast->next;
    tempLast->next = newNode;
}

void atHead(struct Node **head, int n)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = n;
    if (*head == NULL)
        newNode->next = NULL; // list was empty
    else
        newNode->next = *head;
    *head = newNode;
}

void afterN(struct Node *aNode, int n)
{
    if (aNode != NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = n;
        newNode->next = aNode->next;
        aNode->next = newNode;
    }
}
/*from lectures*/
void display(struct Node *ptr)
{
    if (!ptr)
    {
        printf("Linked list is empty\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int countNodes(struct Node *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

int addNodes(struct Node *ptr)
{
    int sum = 0;
    while (ptr)
    {
        sum += ptr->data;
        ptr = ptr->next;
    }
    return sum;
}

int *maxMin(struct Node *ptr)
{
    int *ext = (int *)malloc(4 * sizeof(int)), index = 0;
    ext[0] = INT_MIN;
    ext[2] = INT_MAX;
    ext[1] = ext[3] = -1;
    while (ptr)
    {
        if (ptr->data < ext[2])
        {
            ext[2] = ptr->data;
            ext[3] = index;
        }
        else if (ptr->data > ext[0])
        {
            ext[0] = ptr->data;
            ext[1] = index;
        }
        index++;
        ptr = ptr->next;
    }
    return ext;
}

int search(struct Node **head, struct Node *ptr, int key, int choice)
{
    struct Node *last = NULL; // can assign last = ptr but that's against definition and anyway not needed if foundIndex = 0
    int index = 0;
    while (ptr)
    {
        if (ptr->data == key)
        {
            if (choice)
            {
                if (*head != ptr) // if element is found at index 0, assignment leads to ptr->next = ptr (infinite linked list)
                {
                    last->next = ptr->next;
                    ptr->next = *head;
                    *head = ptr; // magic - just like addHead's last line
                }
            }
            return index;
        }
        last = ptr;
        ptr = ptr->next;
        index++;
    }
    return -1;
}

// integrated insertion function
int insert(struct Node **head, int pos, int x)
{
    int flag = 0; // allocation unsuccessful
    if (pos < 0 || pos > countNodes(*head))
        return flag;
    if (pos == 0) // for head
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = x;
        temp->next = *head; // null if no node existed
        *head = temp;
        flag = 1;
    }
    else // every other position
    {
        struct Node *ptr = *head, *temp;
        int i = 1;
        for (; i <= pos - 1 && ptr != NULL; i++) // stops at a node* n and not n->next
            ptr = ptr->next;
        if (ptr) // prevents accessing invalid position
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = x;
            temp->next = ptr->next;
            ptr->next = temp;
            flag = 1;
        } // redundant now because of the return statement above
    }
    return flag;
}
// O(1) function to insert at end
void insertEnd(struct Node **head, struct Node **end, int n)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = n;
    temp->next = NULL;
    if (*head == *end && *head == NULL)
        *head = *end = temp;
    else
    {
        (*end)->next = temp;
        *end = temp;
    }
}
// insertion in a sorted linked list
void insertSorted(struct Node **head, int n)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = *head;
    temp->data = n;
    if (*head == NULL)
    {
        temp->next = NULL;
        *head = temp;
    }
    else
    {
        while (ptr->next && (ptr->next)->data < temp->data)
            ptr = ptr->next;
        if (*head == ptr && temp->data < ptr->data)
        {
            temp->next = ptr;
            *head = temp;
        }
        else
        {
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
}

int deletion(struct Node **head, int pos)
{
    if (pos <= 0 || pos > countNodes(*head))
    {
        printf("Invalid deletion index\n");
        return INT_MIN;
    }
    if (*head == NULL)
    {
        printf("Linked list is empty\n");
        return INT_MIN;
    }
    struct Node *ptr = *head, *q;
    int deleted, i;
    if (pos == 1)
        *head = ptr->next;
    else
    {
        for (i = 1; i <= pos - 1; i++)
        {
            q = ptr;
            ptr = ptr->next;
        }
        q->next = ptr->next;
    }
    deleted = ptr->data;
    free(ptr);
    return deleted;
}

int isSorted(struct Node *ptr)
{
    int asc = 1, desc = 1, prevAsc = INT_MIN, prevDesc = INT_MAX;
    while (ptr)
    {
        if (asc)
        {
            if (ptr->data >= prevAsc)
                prevAsc = ptr->data;
            else
                asc = 0;
        }
        if (desc)
        {
            if (ptr->data <= prevDesc)
                prevDesc = ptr->data;
            else
                desc = 0;
        }
        if (!(asc + desc))
            return 0;
        ptr = ptr->next;
    }
    if (asc + desc == 2)
        return 3; // printf("All elements are equal\n");
    else if (asc == 1)
        return 1; // printf("Sorted in ascending order\n");
    else
        return 2; // printf("Sorted in descending order\n");
}

void delDups(struct Node *ptr)
{
    if (!isSorted(ptr))
    {
        printf("Linked list is not sorted\n");
        return;
    }
    struct Node *q = ptr->next;
    while (q)
    {
        if (ptr->data != q->data)
        {
            ptr = q;
            q = q->next;
        }
        else
        {
            ptr->next = q->next;
            free(q);
            q = ptr->next;
        }
    }
}

void revArr(struct Node **head)
{
    int *arr = (int *)malloc(sizeof(int) * countNodes(*head)), index = 0;
    struct Node *ptr = *head;
    while (ptr)
    {
        arr[index++] = ptr->data;
        ptr = ptr->next;
    }
    ptr = *head;
    while (ptr)
    {
        ptr->data = arr[--index];
        ptr = ptr->next;
    }
}

void revNext(struct Node **head)
{
    struct Node *p = *head, *q, *r;
    q = r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    *head = q;
}

struct Node *concat(struct Node **firstHead, struct Node *secondHead)
{
    /*using *ptr in signature doesn't work because of pseudo call-by-value nature
    and only the last element of the first list ends up becoming a part of the list*/
    struct Node **thirdHead = firstHead, *p = *firstHead;
    while (p->next) // non-last node for LL#1
        p = p->next;
    p->next = secondHead; // connected
    return *thirdHead;
}

struct Node *mergeSorted(struct Node **firstHead, struct Node **secondHead, struct Node **thirdHead)
{
    struct Node *p = *firstHead, *q = *secondHead;
    struct Node *r1, *r2;
    if (p->data <= q->data)
    {
        thirdHead = firstHead;
        r1 = r2 = *thirdHead;
        p = p->next;
        r1->next = NULL; // writing this line before the previous one nulls out LL#1 permanently
    }
    else
    {
        thirdHead = secondHead;
        r1 = r2 = *thirdHead;
        q = q->next;
        r1->next = NULL; // writing this line before the previous one nulls out LL#2 permanently
    }
    while (p && q)
    {
        if (p->data <= q->data)
        {
            r2->next = p;
            r2 = p;
            p = p->next;
            r2->next = NULL;
        }
        else
        {
            r2->next = q;
            r2 = q;
            q = q->next;
            r2->next = NULL;
        }
    }
    if (p)
        r2->next = p;
    if (q)
        r2->next = q;
    return *thirdHead;
}

int hasLoop(struct Node *ptr)
{
    struct Node *q = ptr;
    do
    {
        ptr = ptr->next;
        q = q->next;
        if (q)
            q = q->next;
    } while (ptr != q && (ptr && q));
    return (ptr != q) ? 0 : 1;
}

// custom creation in a weird, roundabout manner with choice
void create(struct Node **head, struct Node **end, int A[], int n, int choice)
{
    int i, f;
    if (!choice)
    {
        for (i = 0; i < n; i++)
        {
            if (i % 3 == 0 || i == 1)
                atEnd(head, A[i]);
            else if (i % 3 == 2)
                atHead(head, A[i]);
            else
            {
                struct Node *someNode = *head;
                while (someNode->data != A[2])
                    someNode = someNode->next;
                afterN(someNode, A[i]);
            }
        }
    }
    else if (choice == 1)
    {
        for (i = 0; i < n; i++)
        {
            f = insert(head, countNodes(*head), A[i]); // can mimic the actions above
            if (!f)
            {
                printf("Node could not be allocated\n");
                // break;
            }
        }
    }
    else if (choice == 2)
    {
        for (i = 0; i < n; i++)
            insertEnd(head, end, A[i]);
    }
    else if (choice == 3)
    {
        for (i = 0; i < n; i++)
            insertSorted(head, A[i]);
    }
}

/*recursive equivalents follow*/
void rDisplay(struct Node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->data);
        rDisplay(ptr->next);
        printf("%d ", ptr->data); // prints the list in reverse
    }
    else
        printf("\nList displayed in reverse:\n");
}

int rCount(struct Node *ptr)
{
    if (ptr)
        return rCount(ptr->next) + 1;
    return 0;
}

int rAdd(struct Node *ptr)
{
    if (ptr)
        return rAdd(ptr->next) + ptr->data;
    return 0;
}

int rMax(struct Node *ptr)
{ // simplistic
    int x;
    if (!ptr)
        return INT_MIN;
    x = rMax(ptr->next);
    return x > ptr->data ? x : ptr->data;
}

int *rMinMax(struct Node *ptr)
{
    static int extremum[5] = {INT_MIN, -1, INT_MAX, -1, 0};
    if (ptr)
    {
        if (ptr->data < extremum[2])
        {
            extremum[2] = ptr->data;
            extremum[3] = extremum[4];
        }
        else if (ptr->data > extremum[0])
        {
            extremum[0] = ptr->data;
            extremum[1] = extremum[4];
        }
        extremum[4]++;
        rMinMax(ptr->next);
    }
    else
        return 0;
    return extremum;
}

int rSearch(struct Node *ptr, int key, int index)
{
    if (!ptr)
        return -1;
    if (ptr->data == key)
        return index;
    return rSearch(ptr->next, key, index + 1); // may/mayn't write return
}

void revRec(struct Node **head, struct Node *p, struct Node *q)
{
    if (p)
    {
        revRec(head, p->next, p);
        p->next = q;
    }
    else
        *head = q;
}

int main()
{
    struct Node *f = NULL, *g, *h;
    int a[] = {10, 20, 30, 40, 50, 60};
    create(&f, NULL, a, 6, 3);

    g = f->next->next;       // on 30
    h = g->next->next->next; // on 60 - can be on any element after g
    h->next = g;             // loop introduced

    if (!hasLoop(f))
    {
        printf("Linked list contents:\n");
        display(f);
        printf("\n");
    }
    else
        printf("Linked list has a loop\n");

    printf("Program terminated\n");
    return 0;
}