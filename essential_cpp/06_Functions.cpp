/*
 * Functions
 * 
 * Grouping data is a structure.
 * Grouping instructions is a function.
 * 
 * Functions are modules/procedures.
 * 
 * Monolithic programming vs Modular/Procedural programming.
 */

#include <iostream>

using namespace std;

/*
 * Simple function that adds two numbers and returns the sum. This function does not return
 * anything so its return type is 'void'. 'add' is the name of the function, and
 * '(int a, int b)' are 'formal' parameters.
 */
int add(int a, int b)
{
  int sum = a + b;
  return sum;
};

// The parameters which exist in main() are called the 'actual' parameters, and they cannot
// be modified. Formal parameters, copies of the actual parameters, can be modified.
int main()
{
  int a, b;
  cout << "Enter first number: "; cin >> a;
  cout << "Enter second number: "; cin >> b;
  cout << a << " + " << b << " = " << add(a, b); cout << endl;
  return 0;
}