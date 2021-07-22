#include <iostream>
#include <climits>
using namespace std;

int *maxMin(int *arr, int n)
{
    int *ans = new int[2];
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    ans[0] = max;
    ans[1] = min;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int *ans = maxMin(arr, n);
    cout <<ans[0]-ans[1] << endl;
    delete[] arr;
}