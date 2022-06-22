
#include <bits/stdc++.h>
using namespace std;
/**
 *  Check redundant brackets
 *  -   For a given expression in the form of a string, find if there exist
 *      any redundant brackets or not. It is given that the expression contains
 *      only rounded brackets or parenthesis and the input expression will
 *      always be balanced.
 *  -   A pair of the bracket is said to be redundant when a sub-expression is
 *      surrounded by unnecessary or needless brackets.
 *
 *  Input Format :
 *      The first and the only line of input contains a string expression, without
 *      any spaces in between.
 *  Output Format :
 *      The first and the only line of output will print either 'true' or 'false'
 *      (without the quotes) denoting whether the input expression contains redundant
 *      brackets or not.
 *
 *  Constraints:
 *      0 <= N <= 10^6
 *      Where N is the length of the expression.
 *
 *  Time Limit: 1 second
 *
 *  Sample Input 1:
 *      a+(b)+c
 *  Sample Output 1:
 *      true
 *  Explanation:
 *      The expression can be reduced to a+b+c. Hence, the brackets are redundant.
 *
 *  Sample Input 2:
 *      (a+b)
 *  Sample Output 2:
 *      false
 */
/*
    Time Complexity: O(|S|)
    Space Complexity: O(|S|)

    Where '|S|' is the length of the given string.
*/

bool findRedundantBrackets(string &s)
{
    // For keeping track of opening and closing brackets.
    stack<char> brackets;

    int n = s.length();

    // Iterate through the string.
    for (int i = 0; i < n; i++)
    {
        // Push the current character to the stack if it is an operator or an opening bracket.
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            brackets.push(s[i]);
        }

        // If the current character is a closing bracket.
        else if (s[i] == ')')
        {
            // For checking if the current bracket is redundant or not.
            bool isRedundant = true;

            // Keep popping from the stack till we reach an opening bracket.
            while (brackets.top() != '(')
            {
                // If we find a operator then the current bracket is not redundant.
                if (brackets.top() == '+' || brackets.top() == '-' || brackets.top() == '*' || brackets.top() == '/')
                {
                    isRedundant = false;
                }

                brackets.pop();
            }

            brackets.pop();

            // Return true if we did not find any operator before finding the opening bracket.
            if (isRedundant == true)
            {
                return true;
            }
        }
    }

    // If no bracket is redundant then return false.
    return false;
}
int main()
{
    string input;
    cin >> input;
    cout << ((findRedundantBrackets(input)) ? "true" : "false");
}