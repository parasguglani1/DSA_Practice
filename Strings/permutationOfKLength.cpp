#include <bits/stdc++.h>
using namespace std;
int cont = 0;
void printAllKLengthRec(char set[], string prefix, int n, int k)
{
    if (k == 0)
    {

        char firstchar = prefix[0];
        char thirdchar = prefix[1];
        char lastchar = prefix[2];
        cout << firstchar << "b" << thirdchar << "d" << lastchar << endl;
        cont++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        string newPrefix;
        newPrefix = prefix + set[i];
        printAllKLengthRec(set, newPrefix, n, k - 1);
    }
}
void printAllKLength(char set[], int k, int n)
{
    printAllKLengthRec(set, "", n, k);
}
int main()
{
    char set1[] = {'a', 'b', 'c', 'd', 'e'};
    int k = 3;
    printAllKLength(set1, k, 5);
    cout << cont << endl;
}
