#include <iostream>
using namespace std;

int trapRain(int *arr, int n)
{
    int low = 0, high = n - 1;
    int ans = 0, lMax = 0, rMax = 0;
    while (low < high)
    {
        if (arr[low] < arr[high])
        {
            if (arr[low] > lMax)
            {
                lMax = arr[low];
            }
            else
            {
                ans = ans + lMax - arr[low];
            }
            low++;
        }
        else
        {
            if (arr[high] > rMax)
            {
                rMax = arr[high];
            }
            else
            {
                ans = ans + rMax - arr[high];
            }
            high--;
        }
    }
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
    cout << trapRain(arr, n) << endl;
    delete[] arr;
}