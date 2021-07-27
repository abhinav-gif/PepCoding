#include <iostream>
using namespace std;

void rotate(int *arr, int n, int k)
{
    if (k >= 0)
    {
        k = k % n;
        int *temp = new int[k];
        for (int i = n - k, j = 0; i < n; i++, j++)
        {
            temp[j] = arr[i];
        }
        for (int i = n - 1; i >= k; i--)
        {
            arr[i] = arr[i - k];
        }
        for (int i = 0; i < k; i++)
        {
            arr[i] = temp[i];
        }
        delete[] temp;
    }
    else
    {
        k = -1 * k;
        k = k % n;
        int *temp = new int[k];
        for (int i = 0; i < k; i++)
        {
            temp[i] = arr[i];
        }
        for (int i = k; i < n; i++)
        {
            arr[i - k] = arr[i];
        }
        for (int i = n - k, j = 0; i < n; i++, j++)
        {
            arr[i] = temp[j];
        }
        delete[] temp;
    }
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
    int k;
    cin >> k;
    rotate(arr, n, k);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
}