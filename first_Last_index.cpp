#include <iostream>
using namespace std;

void flind(int *arr, int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            int i = mid;
            while (i >= 0 && arr[mid] == arr[i])
            {
                i--;
            }
            cout << "First Index: " << i + 1;
            i = mid;
            while (i < n && arr[mid] == arr[i])
            {
                i++;
            }
            cout << " Last Index: " << i - 1;
            return;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << "-1" << endl;
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
    flind(arr, n, x);
}