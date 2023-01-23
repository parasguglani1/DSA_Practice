#include <iostream>
#include <vector>
using namespace std;

int main()
{

	// vector<int> *vp = new vector<int>(); // Dynamically allocated <- needs to be freed manually
	vector<int> v; // Statically allocated

	/*
	v.push_back(10); // insert 10 at the end
	v.push_back(20); // 20 added after 10
	v.push_back(30); // 30 added after 20

	cout << v[0] << endl;
	cout << v[1] << endl;
	cout << v[2] << endl;

	v[1] = 100; // updating the value
	cout << v[1] << endl;

	// cout << v[3] << endl;
	// size is 3 i.e, index 0 ~ 2, so index 3 will hold garbage value

	cout << v.size() << endl; // size of the array

	//  cout << v.at(3) << endl;
	// this will give IndexOutOfBound error unlike [] which just prints garbage value. So, at() is safer
	// Because if we try to access something out of index, at() will give error.
	// So, always use at() with vector

	for (int x : v)
	{
		cout << x << endl;
	}

	// Remove last element
	v.pop_back();

	for (int x : v)
	{
		cout << x << endl;
	}
	*/

	// size of the internal/underlying array of the vector
	for (int i = 0; i < 100; i++)
	{
		cout << "capacity: " << v.capacity() << endl;
		v.push_back(i + 1);
		cout << "size: " << v.size() << endl;
	}

	// In the beginning the underlying array is zero
	// Then as we insert elements and it fills up, the size increases by power of 2
	// 0 -> 1(2^0) -> 2(2^1) -> 4(2^2) -> 8(2^3) -> ......

	/*
	* We do not use direct indexes to store the data in vector and instead use push_back()
	* Because, in case of push_back() the size of the internal array increases everytime it reaches the limit
	* Just like the dynamic array that we manually built (refer to lecture-7 in the copy)
	* But in case of assigning value with indexes, the size does not increase.
	* We might try to allocate value to the memory location that is not allocated to us.
		This will give us garbage values
	* If we use indexes to put values and if gets out of bound then those values will not be stored
	* We will use [] for only two things,
		1. for getting the value stored in vector
		2. to update the values in vector
	* We will not use it for inserting
	*/
}
