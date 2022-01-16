// Recursion

/*
 * A recursive function is a function that calls itself given a base condition
 * 
 * Type fun(param)
 * {
 *  if (<base condition>)
 *  {
 *    1. ___ // Executes at call time
 *    2. fun(param); // Calling phase
 *    3. ___ // Executes at return time
 *  }
 * }
 * 
 * Recursion has two phases: 1) Calling phase and 2) Returning phase
 * 
 * Difference between a loop and a recursive function:
 * 
 * 1) Loop: A loop only has a calling (ascending) phase.
 * 2) Recursion: A recursive function contains both a calling and returning (descending)
 * phase.
 */

#include <iostream>

using namespace std;

void fun1(int n)
{
  if (n > 0)
  {
    cout << n << endl;
    fun1(n - 1);
  }
}

void fun2(int n)
{
  if (n > 0)
  {
    fun2(n - 1);
    cout << n << endl;
  }
}

int main()
{
  int x = 3;
  fun1(x);
  fun2(x);
  return 0;
}