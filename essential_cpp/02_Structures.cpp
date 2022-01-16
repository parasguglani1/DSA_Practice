/*
 * Structures
 * 
 * Structures can be defined as a collection of data under one name. Its elements can be
 * different data types.
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * Struct can be used to store a variable with at least 2 parts, for example a complex
 * number has 2 parts a and b, used to define a variable i (imaginary number).
 * 
 * a + ib
 */
struct Complex
{
  int real, img;
};
// A rectangle has two parts, length and breadth (width).
struct Rectangle
{
  // Each take a number of bytes, in this case 4 because they are both integers.
  int length, breadth;
};
// Information about a student can include more than two parts.
struct Student
{
  // Each string is 24 bytes
  string firstName, lastName, address;
  // Each int is 4 bytes
  int age;
};
// Here is a data structure for playing cards.
struct Card
{
  string name, suit;
  int rank; 
};


int main()
{
  // Rectangle
  struct Rectangle r = {10, 5};
  // Returns 8 because r is 4 (length) + 4 (breadth)
  cout << "Size of r: " << sizeof(r) << endl;
  // The dot . operator is used to access (read/write) a member of a structure
  cout << "Element of r at index 0: " << r.length << endl;
  // Access the length of r and change it to 15
  r.length = 15;
  cout << "Element of r at index 0: " << r.length << endl;
  cout << endl;

  // Student
  struct Student s; // First student
  struct Student t; // Second student
  s.firstName = "John"; s.lastName = "Smith"; t.age = 14;
  cout << "First student's full name: " << s.firstName << " " <<
    s.lastName << endl;
  cout << "Second student's age: " << t.age << endl;
  cout << endl;

  // Card
  struct Card queenOfHearts;
  queenOfHearts.rank = 11;
  queenOfHearts.name = "Queen";
  queenOfHearts.suit = "Hearts";
  cout << "Queen of Hearts name: " << queenOfHearts.name << endl;
  cout << "Queen of Hearts suit: " << queenOfHearts.suit << endl;
  cout << "Queen of Hearts rank: " << queenOfHearts.rank << endl;
  return 0;
}