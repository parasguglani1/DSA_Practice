// Array As Parameter

#include <iostream>

using namespace std;

// int * fun1(int n)
// {
//   int *p;
//   p = new int[n];
//   return (p);
// }

// int main()
// {
//   int *A;
//   A = fun1(5);
//   cout << A << endl;
//   return 0;
// }

/*
 * Note: For Each loop will not work on pointers, you will have to use a For loop.
 * Important: Arrays cannot be passed by value at all. In the function below, the
 * first param int arr2[] is being passed by address (pointer) and int len is being
 * passed by value.
 * 
 * *A instead of arr2[] can also work here, but brackets are more specific. *A will
 * work on any integer and also arrays. arr2[] should be used when pointing only to
 * an array.
 */

// This function doesn't return an array
void fun1(int arr2[], int len)
{
  cout << "2. Array created inside fun1(): ";
  for (int i = 0; i < len; i++)
  cout << arr2[i] << " ";
  cout << endl;
}

// This function returns an array
int * fun2(int size)
{
  int *p; p = new int[size];
  for (int i = 0; i < size; i++)
  p[i] = i + 1;
  return p;
}

int main()
{
  int arr1[4] = {2, 4, 6, 8},
    arr2[] = {3, 9, 12, 15, 18},
    len = sizeof(arr2)/sizeof(int),
    *q, size = 8;
  // 1. Array created inside main()
  cout << "1. Array created inside main(): ";
  for (int i = 0; i < 4; i++)
  cout << arr1[i] << " "; cout << endl;
  // 2. Array created inside fun1()
  fun1(arr2, len);
  // 3. Array created inside fun2() and returned. q points to what fun2() has returned
  q = fun2(size);
  cout << "3. Array created inside fun2(): ";
  for (int i = 0; i < size; i++)
  cout << q[i] << " "; cout << endl;
  return 0;
}