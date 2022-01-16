/*
 * Structures And Functions
 *
 * These examples lead to what is known as Object Oriented
 * Programming (OOP), the highest level of programming in
 * the C language.
 */

#include <iostream>

using namespace std;

struct Rectangle
{
  int length, width;
};

void initialize(struct Rectangle *r, int l, int w)
{
  r->length = l;
  r->width = w;
  cout << "Rectangle" << endl;
  cout << "Length: " << l << ", Width: " << w;
}

// Returns the area of the rectangle
int area(struct Rectangle r)
{
  return r.length * r.width;
}

void changeLength(struct Rectangle *r, int l)
{
  r->length = l;
  cout << ", New Length: " << l << endl;
}

int main()
{
  struct Rectangle r;
  initialize(&r, 10, 3);
  cout << ", Area: " << area(r);
  changeLength(&r, 15);
  return 0;
}