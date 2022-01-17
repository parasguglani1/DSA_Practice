//To demonstrate strings in C
#include <stdio.h>
#include <stdlib.h>

#define UPPER s[i] >= 'A' && s[i] <= 'Z'
#define LOWER s[i] >= 'a' && s[i] <= 'z'
#define VOWEL s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'\
            ||s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'

int getLength(char* str)
{
    int length = 0;
    while(str[length] != '\0')
        length++;
    /*
    fgets(str_name, size, stream) introduces an extra character '\n'
    The snippet below caters to the problem
    */

    if(str[length-1] == '\n')
    {
        length--;
        str[length] = '\0';
    }
    return length;
}

char* initialize(int* size)
{
    while(1)
    {
        printf("Enter the initial size: ");
        scanf("%d", size);
        if(*size > 0)
            break;
        printf("Invalid input, try again\n");
    }
    scanf("%c"); //takes care of stray newline
    return (char*)malloc(*size*sizeof(char));
}

char* toggleCases(char* s, int size)
{
    int i;
    char* str = (char*)malloc(size*sizeof(char));
    /* char* str;
    can also use without dynamic allocation
    However, should not deallocate later on*/
    for(i = 0; i < size; i++)
    {
        if(UPPER)
            str[i] = s[i] + 32;
        else if(LOWER)
            str[i] = s[i] - 32;
        else
            str[i] = s[i];
    }
    str[i] = s[i]; //adds the null character
    return str;
}

int* vowelCons(char* s, int size)
{
    int i;
    int* ptr = (int*)malloc(2*sizeof(int));
    ptr[0] = ptr[1] = 0;
    for(i = 0; i < size; i++)
    {
        if(VOWEL)
            ptr[0]++;
        else if(UPPER||LOWER)
            ptr[1]++;        
    }
    return ptr;
}

int numWords(char* s, int size)
{
    int i, words = 1;
    for(i = 0; i < size; i++)
    {
        if(i != 0 && s[i] == ' ' && s[i-1] != ' ') //first condition prevents out-of-bounds with index -1
            words++;
    }
    return words;
}

int passwordValidator(char* s, int size)
{
    if(size >= 8 && size <= 15)
    {
        int i, numdig, low, up, spChar;
        numdig = low = up = spChar = 0;
        for(i = 0; i < size; i++)
        {
            if(s[i] == ' ')
            {
                printf("Cannot have blanks\n");
                return 0;
            }
            if(UPPER)
                up++;
            else if(LOWER)
                low++;
            else if(s[i] == '~' || s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$'
            || s[i] == '%' || s[i] == '^' || s[i] == '&' || s[i] == '*' || s[i] == '('
            || s[i] == ')' || s[i] == '-' || s[i] == '+' || s[i] == '{' || s[i] == '}' 
            || s[i] == '[' || s[i] == ']' || s[i] == ';' || s[i] == ':' || s[i] == '|'
            || s[i] == '/' || s[i] == ',' || s[i] == '<' || s[i] == '>' || s[i] == '.'
            || s[i] == '?' || s[i] == '/' || s[i] == '=' || s[i] == '_')
                spChar++;
            else if(s[i] >= 48 && s[i] <= 57)
                numdig++;
        }
        if(!numdig)
        {
            printf("At least one number is required\n");
            return 0;
        }
        if(!up)
        {
            printf("At least one uppercase letter is required\n");
            return 0;
        }
        if(!low)
        {
            printf("At least one lowercase letter is required\n");
            return 0;
        }
        if(!spChar)
        {
            printf("At least one special character is required\n");
            return 0;
        }
    }
    else
    {
        if(size < 8)
            printf("Password should be at least eight characters long\n");
        else
            printf("Password should not be longer than fifteen characters\n");
        return 0;
    }
    return 1;
}

void reverse(char* s, int size)
{
    int i = 0, j = size-1;
    char temp;
    for(;i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

char* revAux(char* s, int size)
{
    char* str = (char*)malloc((size+1)*sizeof(char));
    int i, j;
    for(i = 0, j = size-1; i < size; i++, j--)
        str[i] = s[j];
    str[i] = '\0';
    return str;
}

int comparison(char* a, char* b)
{
    int i, j; char c1, c2;
    for(i = j = 0; a[i] != '\0' && b[j] != '\0'; i++, j++)
    {
        if(a[i] >= 65 && a[i] <= 90)
            c1 = a[i] + 32;
        else
            c1 = a[i];
        if(b[j] >= 65 && b[j] <= 90)
            c2 = b[j] + 32;
        else
            c2 = b[j];

        if(c1 != c2)
            break;
    }
    return (a[i] - b[j]);
}

int palindrome(char* a) //uses auxilliary space
{
    char* b = revAux(a, getLength(a));
    if(comparison(a, b))
        return 0;
    return 1;
}

int altPalindrome(char* s) //does not need auxilliary space
{
    int l = getLength(s), i, j;
    char c1, c2;
    for(i = 0, j = l - 1; i < j; i++, j--)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            c1 = s[i] + 32;
        else
            c1 = s[i];
        if(s[j] >= 'A' && s[j] <= 'Z')
            c2 = s[j] + 32;
        else
            c2 = s[j];

        if(c1 != c2)
            return 0;        
    }
    return 1;
}

int searchLetter(char* s, char f, int size)
{
    int i;
    for(i = 0; i < size; i++)
        if(s[i] == f)
            return 1;
    return 0;
}

void naiveDups(char* s, int size)
{
    //choosing the flag
    char flag = -125, *copy = (char*)malloc(size*sizeof(char));
    int i, j, occ = 0;
    while(searchLetter(s, flag, size))
        flag++;
    //printf("Flag: %d - %c\n", flag, flag);
    //create a copy
    for(i = 0; i < size; i++)
        copy[i] = s[i];
    //printf("Copied as: %s\n", copy);
    //actual process
    for(i = 0; i < size; i++)
    {
        occ = 1;
        if(s[i] != flag)
        {
            for(j = i+1; j < size; j++)
            {
                if(s[i] == s[j])
                {
                    occ++;
                    s[j] = flag;
                }
            }
        }
        if(occ > 1)
            printf("%c (ASCII - %d) occured %d times\n", s[i], s[i], occ);
    }
    free(copy);
}

void hashDups(char* s, int size)
{
    char min = -128, max = 127; int i;
    for(i = 0; i < size; i++)
    {
        if(s[i] < min)
            min = s[i];
        else
        {
            if(s[i] > max)
                max = s[i];
        }
    }
    int hSize = (int)(max - min + 1);
    int* H = (int*)calloc(hSize, sizeof(int));
    for(i = 0; i < size; i++)
        H[s[i] - min]++;
    for(i = 0; i < hSize; i++)
    {
        if(H[i] > 1)
            printf("%c (ASCII - %d) occurred %d times\n", i+min, i+min, H[i]);
    }
    free(H);
}

void bitDups(char* s, int size)
{//values should not repeat more than once, otherwise WE see duplicates
    long int H = 0, x = 0; //8 bytes - 64 bits
    int i, j, arr[64] = {0};
    for(i = 0; i < size; i++)
    {
        x = 1;
        x = x<<s[i] - 65; //lecture had 97 here
        if((x&H) > 0) 
        //not enclosing x&H in parentheses fails the condition
            printf("%c is duplicate\n", s[i]);
        else
            H = H|x;
    }
    /*Displays all array content in uppercase
    i = 0;
    while(H > 0)
    {
        arr[i++] = H%2;
        H /= 2;
    }
    for(j = i-1; j >= 0; j--)
    {
        if(arr[j] == 1)
            printf("%c\n", 65+j);
    }*/
}

int anagramHash(char* s1, int size1, char* s2, int size2)
{
    if(size1 != size2)
    {
        printf("Length mismatch\n");
        return 0;
    }
    char l = s1[0], h = s1[0];
    int i, hSize;
    for(i = 1; i < size1; i++)
    {
        if(s1[i] < l)
            l = s1[i];
        else if(s2[i] < l)
            l = s2[i];
        else if(s1[i] > h)
            h = s1[i];
        else if(s2[i] > h)
            h = s2[i];
    }
    hSize = (int)(h-l)+1;
    int* H = (int*)calloc(hSize, sizeof(int));
    for(i = 0; i < size1; i++)
        H[s1[i]-l]++;
    for(i = 0; i < size1; i++)
    {
        H[s2[i]-l]--;
        if(H[s2[i]-l] < 0)
        {
            free(H);
            printf("Character %c not found adequately in second string\n", s2[i]);
            return 0;
        }
    }
    free(H);
    return 1;
}

void perm(char* s, int l, int k)
{
    static char result[100];
    static int taken[100] = {0}; int i;
    if(k == l)
    {
        result[k] = '\0';
        printf("%s ", result);
    }
    else
    {
        for(i = 0; i < l; i++)
        {
            if(taken[i] == 0) //not taken
            {
                taken[i] = 1; //taken, for calls made next
                result[k] = s[i]; //setting the character from ith index
                perm(s, l, k+1); //k = 0 -> k = 1 (and check all indices until the free one is found) -> ....
                taken[i] = 0; //A->B->C->ABC->C->B gone, C->B->ACB->B->C->A gone, B->.....
            }
        }
    }
}

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permSwap(char* s, int l, int h)
{
    if(l == h)
        printf("%s ",s);
    else
    {
        int i;
        for(i = l; i <= h; i++)
        {
            swap(&s[i], &s[l]);
            permSwap(s, l+1, h);
            swap(&s[i], &s[l]);
        }
    }
}

int main()
{
    /*Catered to the permutations problem but can be modified to 
    make use of the remaining functions that were written earlier*/
    int size; char* str = initialize(&size);
    printf("Enter the string: "); fgets(str, size, stdin);
    int l = getLength(str);
    permSwap(str, 0, l-1);
    printf("\n=======\n");
    perm(str, l, 0);
    printf("\nProgram terminated\n");
    return 0;
}