#include <iostream>
using namespace std;

int *inverse(int *arr, int n)
{
    int *temp = new int[n];

    for (int i = 0; i < n; i++)
    {
        temp[arr[i]] = i;
    }
    return temp;
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
    int *temp = inverse(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
    delete[] arr;
    delete[] temp;
}