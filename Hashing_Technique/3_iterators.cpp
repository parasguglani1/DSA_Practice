#include <bits/stdc++.h>
using namespace std;

int main()
{
    // iterator

    cout << endl
         << endl
         << "using iterator" << endl;
    unordered_map<string, int> xmap;
    xmap["abc"] = 1;
    xmap["abc1"] = 2;
    xmap["abc2"] = 3;
    xmap["abc3"] = 4;
    xmap["abc4"] = 5;
    xmap["abc5"] = 6;
    xmap["abc6"] = 7;

    // By using iterator, we kind of get pointer to a data member
    // by doing, it++ we can iterate through next elements
    // most STL have iterators
    // Each STL have different kind of iterators. The iterators do the same work but how it does the work, is different.

    // Declaration of iterator:
    // STL_NAME<T,..>::iterator iterator_name
    // "STL_NAME<T,..>::iterator" is the data type of the iterator

    unordered_map<string, int>::iterator it;
    // Get the first element of the urordered map. As, it is an unordered map so, we will get any one element
    it = xmap.begin();
    while (it != xmap.end())
    {
        cout << "Key : " << it->first << " Value : " << it->second << endl; // (*it).first => it->first
                                                                            // The output will not be in particular order as we are using unordered map
                                                                            // But, if we had used ordered map, then it would print in sorted order
        it++;
    }
    // when we iterate through all elements and reach after the last element:
    // it = ourmap.end();

    cout << endl
         << endl;
    unordered_map<string, int>::iterator it2 = xmap.find("abc");

    // it takes key and returns a iterator pointing to the key

    cout << it2->first << " " << it2->second << endl;
    return 0;

    // erase
    // ourmap.erase(it2); // erase function takes iterators too instead of key
    /*
    We can not erase elements in a rango for any kind of map as they are bi directional.
    They only support it++ and it--
    It was suported in the previous versions of gcc
    But in the newer version, if we do want to use the ranged erase for bidirectional STL,
    then we need to provide two distinct iterators and not use it + n
     */

    // erasing the map;
    xmap.erase(it, xmap.end());

    // iterator in vector
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }
    // it3 is pointing to the first element
    vector<int>::iterator it3 = v.begin();

    // erase in a range
    v.erase(it3 + 1, it3 + 4); // This will delete from it1 + 1 to it1 + 3

    // iterator is effectively a pointer
    while (it3 != v.end())
    {
        cout << *it3 << endl;
        it3++;
    }
    return 0;
}