#include <bits/stdc++.h>
using namespace std;

int main()
{

    /*
There are two types of maps:
1. Ordered Map - uses Self-balancing BST(Generally in VS code, Red-Black Tree is used) - Time complexity of all operations is O(logn) - <map>
2. Unordered Map - uses HashTable - Time Complexity of all operations is O(1) - <unordered_map>
*/
    unordered_map<string, int> mp; // key is of type "string" and value is of type "int"
    // insert
    pair<string, int> p("abc", 1);
    mp.insert(p);
    mp["def"] = 2;

    // Find
    cout << mp["def"] << endl;
    cout << mp.at("abc") << endl;
    // cout << mp.at("ghi") << endl; // if not found, throw exception - key not found
    cout << mp["ghi"] << endl; // if not found, insert in map - with value 0 and print
    if (mp.count("ghi"))
    { // check presence
        cout << "ghi is present." << endl;
    }

    // Size
    cout << mp.size() << endl;
    cout << mp["xyz"] << endl;
    cout << mp.size() << endl;
    // Erase element
    mp.erase("ghi");

    return 0;
}