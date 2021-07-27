#include <iostream>
using namespace std;

void printChart(int *arr, int n, int mx)
{
    for (int i = 0; i < mx; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= mx - arr[j])
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int max(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
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
    int mx = max(arr, n);
    printChart(arr, n, mx);
    delete[] arr;
}