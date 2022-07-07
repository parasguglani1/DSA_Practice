// CPP program to illustrate
// std::reverse() function of STL
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec1;
    vector<int>::iterator p;

    // Inserting elements in vector
    for (int i = 0; i < 8; i++)
    {
        vec1.push_back(i + 10);
    }
    // Displaying elements of vector
    cout << "Initial Vector:" << endl;
    for (p = vec1.begin(); p < vec1.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    cout << "Reverse only from index 5 to 7 in vector:\n";
    // Reversing elements from index 5 to index 7
    reverse(vec1.begin() + 5, vec1.begin() + 8);

    // Displaying elements of vector after Reversing
    for (p = vec1.begin(); p < vec1.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl
         << endl;

    vector<int> vec2{4, 5, 6, 7};

    cout << "Initial Vector:" << endl;
    for (p = vec2.begin(); p < vec2.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    cout << "Reverse full Vector:" << endl;
    // Reversing directly from beginning to end
    reverse(vec2.begin(), vec2.end());

    // Displaying elements of vector after Reversing
    for (p = vec2.begin(); p < vec2.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}
