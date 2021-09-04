#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *input = new int[n];
    int *ans = new int[n];
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() < input[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(input[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Next greater element for " << input[i] << " is " << ans[i] << endl;
    }
    delete[] input;
    delete[] ans;
}