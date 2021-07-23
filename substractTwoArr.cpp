#include <iostream>
#include <cmath>
using namespace std;

int *substract(int *arr1, int n, int *arr2, int m)
{
    int tSize = max(n, m);
    int *ans = new int[tSize];
    // Initializing 0
    for (int i = 0; i < tSize; i++)
    {
        ans[i] = 0;
    }
    int i = n - 1, j = m - 1, carry = 0, k = tSize - 1;
    while (i >= 0 && j >= 0)
    {
        int sum = 0;
        arr1[i] = carry + arr1[i];
        if (arr2[j] > arr1[i])
        {
            carry = -1;
            sum = arr1[i] + 10 - arr2[j];
        }
        else
        {
            sum = arr1[i] - arr2[j];
        }
        ans[k] = sum;
        k--;
        i--;
        j--;
    }
    while (i >= 0)
    {
        int sum = carry + arr1[i];
        if (sum < 0)
        {
            carry = -1;
            sum = sum + 10;
            ans[k] = sum;
        }
        else
        {
            carry = 0;
            ans[k] = sum;
        }
        k--;
        i--;
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
    int *ans = substract(arr1, n, arr2, m);
    int count = 0;
    for (int i = 0; i < max(n, m); i++)
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