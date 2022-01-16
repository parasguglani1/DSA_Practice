/*
 * Reference
 * 
 * A reference is simply an alias or nickname given to a variable. The refernce is denoted
 * by an ampersand symbol, &.
 * 
 * int a = 10; Variable
 * int *p = a; Pointer
 * int &r = a; Reference
 * 
 * Here, 'a' now has two names: 'a' and 'r'.
 * 
 * Conceptually, a reference does not consume memory as it merely uses the same memory as
 * what it is referring to.
 */

#include <iostream>

using namespace std;

int main()
{
  int a = 10;
  int *p = &a;
  int &r = a;
  cout << "a: " << a << endl;
  cout << "*p: " << *p << endl;
  cout << "&r: " << r << endl;
  // Note: When you change the reference's value, the value of what it is referring to
  // also changes to that value.
  r = 15;
  cout << "a: " << a << endl;
  return 0;
}