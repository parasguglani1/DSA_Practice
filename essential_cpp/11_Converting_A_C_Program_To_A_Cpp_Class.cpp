// OOP: Converting C to C++

#include <iostream>

using namespace std;
// Here, instead of struct we'll say class
// Class/Object
class Rectangle
{
  // In C++, "class" is private by default whereas "struct" is public by default.
  private:
  int length, width;
  /*
   * Then include all of the functions nested inside the class, remove "struct
   * Rectangle *r" as a parameter for all functions, and Declare the functions
   * as public.
   */
  public:
  // Class/Object Constructor
  Rectangle(int l, int w)
  {
    // Now remove r-> as length and width are now directly accessible
    length = l;
    width = w;
    cout << "Rectangle" << endl;
    cout << "Length: " << l << ", Width: " << w;
  }

  int area()
  {
    // Then remove r. here for the same reason as stated above
    return length * width;
  }

  void changeLength(int l)
  {
    // Again, no need for r->
    length = l;
    cout << ", New Length: " << l << endl;
  }
};

int main()
{
  // "struct Rectangle r" becomes "Rectangle r", in doing so it becomes an object
  Rectangle r(10, 3);
  /*
   * "initialize(&r, 10, 3" is now "r.initialize(10, 3)". The reason for this is
   * because all of the functions are now part of class Rectangle. In other words,
   * r is the object and each function is now a member of that object.
   */
  // r.initialize(10, 3);
  /*
   * Now get rid of the initialize function altogether, and directly initialize
   * the variables like so "Rectangle r(10, 3);"
   */
  // "area(r)" is now "r.area()"
  cout << ", Area: " << r.area();
  // "changeLength(&r, 15)" becomes "r.changeLength(15)"
  r.changeLength(15);
  return 0;
}