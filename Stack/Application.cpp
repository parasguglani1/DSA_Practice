//Applications of a stack

#include "LLStacks.h"
#include <cmath>

bool checkBal(string s)
{
    Stack<char> stk;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(' ||s[i] == '{' || s[i] == '[')
            stk.push(s[i]);
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if(stk.isEmpty())
                return false; //extra closing brackets/parentheses/braces
            char e = stk.pop();
            if(e < 90)
            {
                if(s[i] - e != 1) //( = 40, ) = 41
                    return false;
            }
            else
            {
                if(s[i] - e != 2) //{ = 123, } = 125, [= 91, ] = 93
                    return false;
            }
        }
    }
    if(stk.isEmpty())
        return true;
    return false; //extra opening parentheses/brackets/braces
}

int isOperand(char c)
{//% only for evaluation function evalPF()
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')' || c == '%')
        return 0;
    else 
        return 1;
}

int precedence(char c, int flag)
{
    if(c == '+' || c == '-')
        return 1+flag;
    else if(c == '*' || c == '/')
        return 2+flag;
    else if(c == '^')
        return 6-flag;
    else if(c == '(')
    {
        if(flag == 0)
            return 7;
        else
            return 0;
    }
    //can use to remove the need for isOperator() for trivial situations 
    return 0; //also for c == ')'
}

string toPostFix(string infix)
{
    Stack<char> stk; string postfix = "";
    int l = infix.length(), i = 0, iteration = 0;
    while(i < l)
    {
        if(isOperand(infix[i]))
            postfix += infix[i++];
        else
        {
            if(precedence(infix[i], 0) > precedence(stk.stackTop(), 1))
                stk.push(infix[i++]);
            else
            {
                if(infix[i] == ')' && stk.stackTop() == '(')
                {
                    stk.pop();
                    i++;
                }
                else
                    postfix += stk.pop();
            }
        }
    }
    while(!stk.isEmpty())
    {
        char c = stk.pop();
        if(c != '(')
            postfix += c;
    }
    return postfix;
}

int evalPF(string postfix)
{
    Stack<int> stk; int l = postfix.length();
    short int op1, op2;
    for(int i = 0; i < l; i++)
    {
        if(isOperand(postfix[i]))
        {
            if(postfix[i] >= 48 && postfix[i] <= 57)
                stk.push(postfix[i] - 48);
            else
                throw invalid_argument("Erroneous input");
        }
        else
        {
            op2 = stk.pop(); op1 = stk.pop();
            switch(postfix[i])
            {
                case '+':
                    stk.push(op1+op2);
                    break;
                case '-':
                    stk.push(op1-op2);
                    break;
                case '*':
                    stk.push(op1*op2);
                    break;
                case '/':
                    if(op2 != 0)
                        stk.push(op1/op2);
                    break;
                case '^':
                    stk.push((int)pow(op1, op2));
                    break;
                case '%':
                    stk.push(op1%op2);
                    break;
            }  
        }
    }
    return stk.pop();
}

int main()
{
    string s; int c; 
    while(true)
    {
        cout<<"1. Check for balanced parentheses/braces/brackets\n2. Convert from infix to postfix\n";
        cout<<"3. Evaluating postfix expression with single digit numbers\n0. Quit the menu\nEnter your choice: "; cin>>c;
        switch(c)
        {
            case 1:
            {
                cout<<"Enter an arithmetic expression: ";
                cin>>ws; getline(cin, s);
                if(checkBal(s))
                    cout<<"Balanced with respect to parentheses\n";
                else
                    cout<<"Not Balanced with respect to parentheses\n";
                break;
            }
            case 2:
            {
                cout<<"Enter an infix expression: ";
                cin>>ws; getline(cin, s);
                if(checkBal(s)) //safety measure
                    cout<<"Postfix equivalent: "<<toPostFix(s)<<"\n";
                else
                    cout<<"Cannot convert due to unbalanced parentheses\n";
                break;
            }
            case 3:
            {
                cout<<"Enter a postfix expression with single digit positive numbers: ";
                cin>>ws; getline(cin, s);
                try
                {
                    cout<<"Numeric equivalent: "<<evalPF(s)<<"\n";
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            case 0:
                break;
            default:
                cout<<"Invalid choice, try again\n";
        }
        if(c == 0)
            break;
    }
    cout<<"Program terminated\n";
    return 0;
}
