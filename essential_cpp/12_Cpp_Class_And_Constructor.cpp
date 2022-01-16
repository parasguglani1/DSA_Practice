// C++ Class and Constructor

#include <iostream>

using namespace std;

class Rectangle
{
  private:
    int length, width;
  public:
    // Rectangle(), area(), and perimeter() are known as "facilitators"
    Rectangle() { length = width = 1; }
    Rectangle(int l, int w);
    int area();
    int perimeter();
    // get functions are known as "accessors"
    int getLength() { return length; }
    // set functions are known as "mutators"
    void setLength(int l) { length = l; }
    // Destructor
    ~Rectangle();
};

// To define functions outside of class you must use "::", aka the "scope
// resolution operator"
Rectangle::Rectangle(int l, int w) { length = l; width = w; }
int Rectangle::area() { return length * width; }
int Rectangle::perimeter() { return 2 * (length + width); }
Rectangle::~Rectangle() {}

int main()
{
  Rectangle r(10, 5); r.setLength(20);
  cout << "Area: " << r.area() << ", "; cout << "Perimeter: " << r.perimeter() <<
    ", "; cout << "Length: " << r.getLength() << endl;
  return 0;
}