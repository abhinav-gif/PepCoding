#include <iostream>
using namespace std;

void cf(int *arr, int n, int x)
{
    int low = 0, high = n - 1, c = -1, f = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            f = arr[mid], c = arr[mid];
            cout << arr[mid] << " " << arr[mid] << endl;
            return;
        }
        // else if (mid + 1 < n && arr[mid] < x && arr[mid + 1] > x)
        // {
        //     f = arr[mid], c = arr[mid + 1];
        //     cout << arr[mid] << " " << arr[mid + 1] << endl;
        //     return;
        // }
        else if (arr[mid] > x)
        {
            c = arr[mid];
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            f = arr[mid];
            low = mid + 1;
        }
    }
    cout << "ceil: " << c << " "
         << "floor: " << f << endl;
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
    cf(arr, n, x);
}