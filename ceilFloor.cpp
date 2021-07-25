#include <iostream>
using namespace std;

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
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            cout << arr[mid] << " " << arr[mid] << endl;
            break;
        }
        else if (arr[mid] < x && arr[mid + 1] > x)
        {
            cout << arr[mid] << " " << arr[mid + 1] << endl;
            break;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
    }
}