// Factorial Recursion

/*
 * n! = 1 * 2 * 3 * ... * n
 * 5! = 1 * 2 * 3 * 4 * 5
 * 
 * Write a recursive program to find n!
 */

#include <iostream>

using namespace std;

int fact(int n)
{
  if (n == 0)
    return 1;
  else
    return fact(n - 1) * n;
}

int main()
{
  int f = fact(5);
  cout << f << endl;
  return 0;
}