#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ASCII code (for English language) and Unicode (international languages).

ASCII: For every character, there is a code behind it. For example:
A - 65, B - 66, C - 67... Z - 90. a - 97, b - 98, c - 99... z- 122.
For numbers as well: 0 - 48, 1 - 49... 9 - 57. For every symbol on a keyboard,
there is an ASCII code available: ENTER - 10, SPACE - 13, ESC - 27...
ASCII code start from 0 to 127 (total 128). 7 bits are enough to represent them (2^7 = 128),
but 7 bits aren't allocated, it's 1 byte (8 bits).

Unicode: They take 2 bytes of memory (16 bits, can be represented as hexadecimal codes) as
4x4-bits, example: C034 */

// Length using while loop
int str_length1(char s[])
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
    return i;
}

// Length using for loop
int str_length2(char *s)
{
    int counter = 0;
    for (int i = 0; s[i]; i++)
    {
        counter++;
    }
    return counter;
}

// Lowercase: the diff between a capital letter and its lowercase is 32
void lower_case(char A[])
{
    for (int i = 0; A[i] != '\0'; i++)
    {
        A[i] += 32;
    }
}

// Uppercase: by subtracting 32
void upper_case(char B[])
{
    for (int i = 0; B[i] != '\0'; i++)
    {
        B[i] -= 32;
    }
}

// Toggle cases: upper becomes lower and vice-versa
void toggle(char C[])
{
    for (int i = 0; C[i] != '\0'; i++)
    {
        if (C[i] >= 65 && C[i] <= 90) // If letter is uppercase
        {
            C[i] += 32;
        }
        else if (C[i] >= 'a' && C[i] <= 'z') // Also possible
        {
            C[i] -= 32;
        }
    }
}

// Vowel count
int vowel_count(char *s)
{
    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'A' ||
            s[i] == 'e' || s[i] == 'E' ||
            s[i] == 'i' || s[i] == 'I' ||
            s[i] == 'o' || s[i] == 'O' ||
            s[i] == 'u' || s[i] == 'U')
        {
            counter++;
        }
    }
    return counter;
}

// Consonant count
int consonant_count(char *s)
{
    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'A' ||
            s[i] == 'e' || s[i] == 'E' ||
            s[i] == 'i' || s[i] == 'I' ||
            s[i] == 'o' || s[i] == 'O' ||
            s[i] == 'u' || s[i] == 'U')
        {
            continue;
        }
        else if (s[i] >= 65 && s[i] <= 90 ||
                 s[i] >= 97 && s[i] <= 122)
        {
            counter++;
        }
    }
    return counter;
}

// Consonant and vowel count
void count_consonants_vowels(char *s)
{
    int v_counter, c_counter;
    v_counter = c_counter = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'A' ||
            s[i] == 'e' || s[i] == 'E' ||
            s[i] == 'i' || s[i] == 'I' ||
            s[i] == 'o' || s[i] == 'O' ||
            s[i] == 'u' || s[i] == 'U')
        {
            v_counter++;
        }
        else if (s[i] >= 65 && s[i] <= 90 ||
                 s[i] >= 97 && s[i] <= 122)
        {
            c_counter++;
        }
    }
    printf("Consonants: %d \nVowels: %d \n", c_counter, v_counter);
}

int count_words(char *s)
{
    int words = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ' && s[i - 1] != ' ')
        {
            words++;
        }
    }
    return words + 1;
}

int main(void)
{
    // Representing a character
    char temp;
    temp = 'A'; // Must be in single quotes and only one character

    printf("%c \n", temp); // A
    printf("%d \n", temp); // 65
    // C++: cout << temp (will display A)

    // Array of characters
    char x[5]; // Declaration
    char y[5] = {'A', 'B', 'C', 'D', 'E'}; // Declaration with initialization
    char z[] = {'A', 'B', 'C', 'D', 'E'}; // Size will depend
    char a[] = {64, 65, 66, 67, 68};
    char b[5] = {'A', 'B'}; // Other characters initialized to 0
    printf("%d \n", b[2]); // 0

    // Strings vs Array of Characters
    char name1[10] = {'J', 'o', 'h', 'n'}; // array of characters
    char name2[10] = {'J', 'o', 'h', 'n', '\0'}; // string
    // \0 is a NULL character / string delimiter / end of string character / string terminator
    char name3[] = "John"; // Like this, \0 will be automatically included
    char *name4 = "John"; // Implicitly allocated in heap memory
    // name4 will be a character pointer pointing to a string in heap

    // Printing strings
    printf("%s \n", name2); // John

    // Scanning strings (only one word)
    scanf("%s", name2); // If yoaju type "David" it will be stored in name2
    printf("%s \n", name2); // David

    // Scanning multiple words
    fflush(stdin); // Use this after scanf and before gets

    gets(name2); // Suppose you type "Taj Mahal"
    printf("%s \n", name2); // Taj Mahal

    // Length with empty for loop in main
    char *s = "Welcome";
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {

    }
    printf("Length is %d \n", i);

    // Length: implemented functions
    char s1[10] = {'W', 'e', 'l', 'c', 'o', 'm', 'e', '\0'};
    printf("%d \n", str_length1(s1));

    char *s2 = "Welcome";
    printf("%d \n", str_length2(s2));

    // Length: built-in function
    printf("%d \n", strlen(s1));
    printf("%d \n", strlen(s2));

    // Changing case
    char A[] = "WELCOME";
    lower_case(&A);
    printf("%s \n", A);

    char B[] = "welcome";
    upper_case(&B);
    printf("%s \n", B);

    char C[] = "w3LCOM3";
    toggle(&C);
    printf("%s \n", C);

    // Counting vowels
    char D[] = "How are you";
    printf("%d \n", vowel_count(D));

    // Counting consonants
    printf("%d \n", consonant_count(D));

    // Consonants and vowels
    count_consonants_vowels(D);

    // Counting words
    printf("%d \n", count_words(D));
    char E[] = "How are   u"; // Extra spaces
    printf("%d \n", count_words(E)); // It handles extra spaces correctly

    return 0;
}
