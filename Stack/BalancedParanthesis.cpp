#include <iostream>
#include <stack>
using namespace std;

bool checkParanthesis(string s)
{
    stack<char> s1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            s1.push(s[i]);
        }
        else if (s[i] == ']')
        {
            if (s1.top() != '[')
            {
                return false;
            }
            else
            {
                s1.pop();
            }
        }
        else if (s[i] == '}')
        {
            if (s1.top() != '{')
            {
                return false;
            }
            else
            {
                s1.pop();
            }
        }
        else if (s[i] == ')')
        {
            if (s1.top() != '(')
            {
                return false;
            }
            else
            {
                s1.pop();
            }
        }
    }
    return s1.empty();
}

int main()
{
    string s;
    getline(cin, s);
    if (checkParanthesis(s))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}