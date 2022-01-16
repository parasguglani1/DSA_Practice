// Types of Recursion:

#include <iostream>

using namespace std;

// 1. Tail Recursion - Linear Recursion
// When the recursive function call is the last statement in the function

// Complexity | Time: O(n), Space: O(n)
void fun1(int n)
{
  if (n > 0)
  {
    cout << n << endl;
    fun1(n - 1);
    // Not tail recursion
    // fun (n - 1) + n;
  }
}

// It is better to convert a tail recursion to a loop, O(1) Space Complexity.
void fun2(int n)
{
  while (n > 0)
  {
    cout << n << endl;
    n--;
  }
}

// 2. Head Recursion - Linear Recursion
// All processing is done at returning time

void fun3(int n)
{
  if (n > 0)
  {
    fun3(n - 1);
    cout << n << endl;
  }
}

// 3. Tree Recursion
// Calls itself more than once

// Time Complexity: O(2^n), Exponential Time (For this example, not every tree
// recursive function will have this time complexity), Space Complexity: O(n)
void fun4(int n)
{
  if (n > 0)
  {
    cout << n << endl;
    fun4(n - 1);
    fun4(n - 1);
  }
}

// 4. Indirect Recursion
// Recursion in a circular fashion A calls B, then B calls A.

void funB(int n);

void funA(int n)
{
  if (n > 0)
  {
    cout << n << endl;
    funB(n - 1);
  }
}

void funB(int n)
{
  if (n > 1)
  {
    cout << n << endl;
    funA(n / 2);
  }
}

// 5. Nested Recursion
// The parameter itself is a recursive call

int fun5(int n)
{
  if (n > 100)
  {
    return n - 10;
  } else {
    return fun5(fun5(n + 11));
  }
}

int main()
{
  int r = fun5(30);
  cout << r << endl;
  return 0;
}