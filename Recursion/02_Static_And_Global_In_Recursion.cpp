// Static and Global In Recursion

#include <iostream>

using namespace std;

// Global variable accessible to all functions
int x = 0;

int fun(int n)
{
  // Static variable accessible only to fun()
  // static int x = 0;
  if (n > 0)
  {
    x++;
    return fun(n - 1) + x;
  }
  return 0;
}

int main()
{
  int r;
  r = fun(5);
  cout << r << endl;
  return 0;
}