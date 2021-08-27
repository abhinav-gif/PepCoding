#include <iostream>
#include <stack>
using namespace std;

bool isDup(string s)
{
    stack<char> s1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ')' && s[i] != '}' && s[i] != ']')
        {
            s1.push(s[i]);
        }
        else
        {
            int count = 0;
            while (s1.top() != '(' && s1.top() != '{' && s1.top() != '[')
            {
                s1.pop();
                count++;
            }
            s1.pop();
            if (count == 0)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string s;
    getline(cin, s);
    if (isDup(s))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}