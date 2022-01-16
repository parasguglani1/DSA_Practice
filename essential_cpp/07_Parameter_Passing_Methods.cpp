/*
 * Parameter Passing Methods
 * 
 * 1. Pass by value
 * 2. Pass by address, *
 * 3. Pass by reference, &
 * 
 * 'Pass by value' and 'pass by address' are more often used than 'pass by reference'.
 */

#include <iostream>

using namespace std;

/*
 * 1. In 'Pass/Call by value', any changes made to formal parameters will not be reflected to
 * the actual parameters. When you don't actually have to modify parameters, you should use
 * this method of 'pass by value', and when you want to return a result. The function example
 * in the previous 6_Functions.cpp uses 'pass by value' because it is a) not modifying the
 * actual parameters, and b) needs to return a value.
 */

int add(int a, int b)
{
  int sum = a + b;
  return sum;
};

/*
 * 2. In 'Pass/Call by address', the addresses of actual parameters are passed through formal
 * parameters and formal parameters must be pointers. Any changes made inside the function
 * will modify actual parameters using indirect access.
 * 
 * Here, all x's and y's must be turned into pointers, *. This is called 'dereferencing' which
 * is used as a means of accessing the data of actual parameters.
 */

void swap(int *x, int *y)
{
  int temp; temp = *x; *x = *y; *y = temp;
};

/*
 * 3. Just like the previous passing method, 'Pass/Call by reference' modifies the actual
 * parameters. The code of that function will be copied/pasted at function call. It's not
 * advisable to use this method when dealing with complex logic. Call by reference should
 * be used very carefully as it is a more powerful feature of C++.
 */

void swap(int &x, int &y)
{
  int temp; temp = x; x = y; y = temp;
};

// Main function

int main()
{
  int a, b;
  a = 10; b = 20;
  swap(a, b);
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  return 0;
}