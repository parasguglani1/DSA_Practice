// Sum Of N Using Recursion

/*
 * Find the sum of the first n natural numbers using recursive and iterative methods,
 * and the formula 1+ 2+ ... + n = n(n+1) / 2, for n a natural number.
 */

#include <iostream>

using namespace std;

// Recursive
int sumRec(int n)
{
  if (n == 0)
    return 0;
  return sumRec(n - 1) + n;
}

// Iterative
int sumItr(int n)
{
  int s = 0;
  for (int i = 1; i <= n; i++)
    s = s + i;
  return s;
}

int main()
{
  int r = sumItr(5);
  cout << r << endl;
  return 0;
}