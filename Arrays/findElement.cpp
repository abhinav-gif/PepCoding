#include <iostream>
#include <algorithm>
using namespace std;

int bs(int *arr, int n, int x)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int ls(int *arr, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

bool isSorted(int *arr, int n)
{
    int i = 0;

    while (i < n - 1 && arr[i] <= arr[i + 1])
    {
        i++;
    }
    if (i < n - 1 && arr[i] > arr[i + 1])
    {
        return false;
    }
    return true;
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
    int x;
    cin >> x;
    if (isSorted(arr, n))
    {
        cout << "Binary Search" << endl;
        cout << bs(arr, n, x) << endl;
    }
    else
    {
        cout << "Linear Search" << endl;
        cout << ls(arr, n, x) << endl;
    }

    delete[] arr;
}