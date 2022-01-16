// Template Classes

#include <iostream>

using namespace std;

// Place this before all functions and replace all data types with template class name, "T"
template <class T>
class Arithmetic
{
  private:
  T a, b;
  public:
  Arithmetic(T a, T b);
  T add(); T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
  this->a = a;
  this->b = b;
}

// T in front of Arithmetic
template <class T>
T Arithmetic<T>::add()
{
  T sum = a + b;
  return sum;
}

template <class T>
T Arithmetic<T>::sub()
{
  T diff = a - b;
  return diff;
}

int main()
{
  // Define the data type here
  Arithmetic<int> ar1(10, 5);
  cout << ar1.add() << endl;
  Arithmetic<float> ar2(9.5, 8.25);
  cout << ar2.sub() << endl;
  return 0;
}