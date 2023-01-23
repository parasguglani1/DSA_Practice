/*
 * Pointers
 *
 * Pointers are address variables that refer to a specific address in memory. Pointers are
 * used for indirectly accessing data. Why would you need to access data indirectly?
 *
 * In memory, a program is divided into 3 parts: The code section, stack section, and heap
 * section. Heap memory is stored outside the program. One of the reasons to use a pointer
 * is to access memory stored outside of the program, in the heap. The main reason to use a
 * pointer is to access resources which exist outside of a program. Pointers are also used
 * in passing parameters.
 *
 * 1. Accessing heap memory.
 * 2. Accessing resources.
 * 3. Passing parameters.
 */

#include <iostream>

using namespace std;

int main()
{
  // Data variable
  int a = 10;
  // Address variable (Pointer)
  int *b = &a;
  /*
   * b exists in a different address and literally points to a.
   * a: [10] Address: 200/201 <- b: [200/201] Address: 210/211
   * int *b (declaration) = &a; (initialization)
   * *b is called dereferencing
   */
  cout << "a: " << a << endl;
  cout << "b: " << *b << endl;
  cout << endl;
  // Whenever you declare a variable, it will exist inside the stack
  int *p;
  // When you want to get a variable in the heap, you have to declare 'malloc' (in C),
  // Memory Allocation in C
  // p = (int *)malloc(5 * sizeof(int));
  // in C++
  p = new int[5];
  p[0] = 2;
  p[1] = 9;
  p[2] = 43;
  p[3] = 67;
  p[4] = 72;
  cout << "Elements in array p: " << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << p[i] << endl;
  }
  /*
   * Whenever you are dynamically using memory, you must delete it afterward. In other
   * words, you must deallocate the memory you allocated in heap. Allocated memory is
   * automatically deleted when the program ends. Note: Every pointer is 8 bytes (in 64-bit
   * machines). In other words, a pointer is always independent of its data type.
   *
   * In C
   * free(p);
   */
  int *p1;
  char *p2;
  float *p3;
  double *p4;
  struct Rectangle *p5;

  cout << sizeof(p1) << '\n';
  cout << sizeof(p2) << '\n';
  cout << sizeof(p3) << '\n';
  cout << sizeof(p4) << '\n';
  cout << sizeof(p5);

  cout << '\n';

  // In C++
  delete[] p;
  return 0;
}