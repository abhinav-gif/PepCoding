#include <iostream>
#include <cmath>
using namespace std;

int *sum(int *arr1, int n, int *arr2, int m)
{
    int tSize = max(n, m) + 1;
    int *ans = new int[tSize];
    // Initializing 0
    for (int i = 0; i < tSize; i++)
    {
        ans[i] = 0;
    }
    int i = n - 1, j = m - 1, carry = 0, k = tSize - 1;
    while (i >= 0 && j >= 0)
    {
        int sum = carry + arr1[i] + arr2[j];
        carry = sum / 10;
        sum = sum % 10;
        ans[k] = sum;
        k--;
        i--;
        j--;
    }
    while (i >= 0)
    {
        int sum = carry + arr1[i];
        carry = sum / 10;
        sum = sum % 10;
        ans[k] = sum;
        k--;
        i--;
    }
    while (j >= 0)
    {
        int sum = carry + arr2[j];
        carry = sum / 10;
        sum = sum % 10;
        ans[k] = sum;
        k--;
        j--;
    }
    if (carry != 0)
    {
        ans[k] = carry;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *arr1 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    int *arr2 = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    int *ans = sum(arr1, n, arr2, m);
    int count = 0;
    for (int i = 0; i < max(n, m) + 1; i++)
    {
        if (ans[i] > 0)
        {
            count = 1;
        }
        if (count == 1)
        {
            cout << ans[i] << " ";
        }
    }
    cout << endl;
    delete[] arr1;
    delete[] arr2;
    delete[] ans;
}