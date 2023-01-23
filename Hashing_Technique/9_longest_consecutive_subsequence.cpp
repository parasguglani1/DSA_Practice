/* Longest Consecutive Sequence
Send Feedback
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
Output format:
The first and only line of output contains sta  rting and ending element of the longest consecutive sequence. If the length of longest consecutive sequence, then just print the starting element.
Constraints :
0 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6
Sample Output 1 :
8 12
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 16 */

#include <bits/stdc++.h>
using namespace std;
// using sorting to find longest ignoring order
int findLongestConseqSubseq(int a[], int N)
{
    int count = 0, max = 0;
    sort(a, a + N);
    for (int i = 0; i < N; i++)
    {
        if (a[i + 1] - a[i] == 1)
        {
            ++count;
        }
        else if (a[i + 1] - a[i] == 0)
        {
            continue;
        }
        else
        {
            if (max < count)
            {
                max = count;
            }
            count = 0;
        }
    }

    return max + 1;
}

pair<int, int> getLongestConsecutiveSubsequenceSet(int arr[], int n)

{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    pair<int, int> ans;
    int longestStreak = 0;
    // for each loop where nums is vector name and num is element
    // for(int num:nums)
    for (int i = 0; i < n; i++)
    {
        if (!s.count(arr[i] - 1))
        {
            int currentnum = arr[i];
            int currentStreak = 1;

            while (s.count(currentnum + 1))
            {

                currentnum++;
                currentStreak++;
            }
            if (currentStreak > longestStreak)
            {
                longestStreak = currentStreak;
                ans.first = arr[i];
                ans.second = currentnum;
            }
        }
    }
    // cout << ans.first << " " << ans.second << endl;
    return ans;
    // return longestStreak;
}
// method 2 returning whole vector and using map instead of set
/* vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, int> countMap;
    vector<int> results;

    for (int i = 0; i < n; i++)
    {
        countMap[arr[i]]++;
    }

    int start_element = 0, n_elements = 0;

    for (int i = 0; i < n; i++)
    {
        if (countMap.find(arr[i] - 1) == countMap.end())
        {
            int next_consecutive_element = arr[i];
            while (countMap.find(next_consecutive_element) != countMap.end())
                next_consecutive_element++;

            if (n_elements < next_consecutive_element - arr[i])
            {
                n_elements = next_consecutive_element - arr[i];
                start_element = arr[i];
            }
        }
    }

    for (int i = start_element; i < start_element + n_elements; i++)
        results.push_back(i);
    return results;
} */

// method 3 vector of pairs with forward and backward propogation
/*
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    // Your Code goes here
    vector<pair<int, int>> pairs_vector;
    // in this vector first element of each pair is the start and second element is the max_length.
    map<int, bool> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]] = true;
    }
    int max_length = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        int current_length = 1;
        int current_start = 0;
        if (m[arr[i]] = true)
        {
            m[arr[i]] = false;
            // forward propagation from arr[i]
            int element_at_position = arr[i];
            while (m[element_at_position + 1] == true)
            {
                current_length += 1;
                m[element_at_position + 1] = false;
                element_at_position++;
            }
            // backward propagation from arr[i]
            element_at_position = arr[i];
            current_start = element_at_position;
            while (m[element_at_position - 1] == true)
            {
                m[element_at_position - 1] = false;
                current_start--;
                current_length++;
                element_at_position--;
            }
        }
        if (current_length >= max_length)
        {
            max_length = current_length;
            start = current_start;
            pair<int, int> p;
            p.first = start;
            p.second = max_length;
            pairs_vector.push_back(p);
            // in this vector first element of each pair is the START and second element is the MAX_LENGTH.
        }
    }
    if (max_length == 1 && start == arr[n - 1])
    {
        vector<int> temp;
        temp.push_back(arr[0]);
        return temp;
    }
    for (int i = 0; i < n; i++)
    {
        int starting_element = arr[i];
        for (int j = 0; j < pairs_vector.size(); j++)
        {
            if (starting_element == pairs_vector[j].first && max_length == pairs_vector[j].second)
            {
                vector<int> temp;
                for (int k = starting_element; k < starting_element + max_length; k++)
                {
                    temp.push_back(k);
                }
                return temp;
            }
        }
    }
} */

// similar to method 3

/* vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    // Your Code goes here
    vector<int> v;
    if (n == 0)
        return v;
    if (n == 1)
    {
        v.push_back(arr[0]);
        return v;
    }

    // unordered map is implemented using hash table
    //  int m[n];
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]] = 1;
    }

    int starting = arr[0];
    int maxnum = 0;
    int currnum = 1;

    for (int i = 0; i < n; i++)
    {

        currnum = 1;
        if (m[arr[i]] == 0)
        {
            continue;
        }

        m[arr[i]] = 0;
        // currnum+=1;

        // search forward
        int index = 0;
        int s = arr[i];
        for (int j = arr[i] + 1;; j++)
        {
            if (m[j] == 1)
            {
                currnum += 1;
                m[j] = 0;
            }
            else
            {
                break;
            }
        }

        // search backwards
        for (int j = arr[i] - 1;; j--)
        {
            if (m[j] == 1)
            {
                s = j;
                currnum += 1;
                m[j] = 0;
            }
            else
            {
                break;
            }
        }
        if (currnum == maxnum)
        {
            // find index of first seq that came in the array
            int ans1 = starting;
            int ans2 = s;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == ans1)
                {
                    starting = ans1;
                    break;
                }
                else if (arr[i] == ans2)
                {
                    starting = ans2;
                    break;
                }
            }
        }
        if (currnum > maxnum)
        {
            maxnum = currnum;
            starting = s;
        }
    }
    for (int i = starting; i < maxnum + starting; i++)
    {
        v.push_back(i);
    }
    return v;
} */
/* vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = i;
    }
    vector<int> res;
    int maxLength = 0;
    int startElement = 0;
    int startIndex = n;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int count;
        if (mp[num] != -1)
        {
            count = 0;
            int index = mp[num];
            while (mp.find(num) != mp.end() && mp[num] != -1)
            {
                count++;
                mp[num] = -1;
                num++;
            }
            num = arr[i] - 1;
            while (mp.find(num) != mp.end() && mp[num] != -1)
            {
                count++;
                index = mp[num];
                mp[num] = -1;
                num--;
            }
            if (count > maxLength || (count == maxLength && index < startIndex))
            {
                // print(mp);
                maxLength = count;
                startElement = num + 1;
                startIndex = index;
            }
        }
    }
    for (int i = startElement; i < startElement + maxLength; i++)
    {
        res.push_back(i);
    }
    return res;
} */
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pair<int, int> ans = getLongestConsecutiveSubsequenceSet(a, n);
    cout << ans.first << " " << ans.second;

    return 0;
}