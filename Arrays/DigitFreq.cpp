#include <iostream>
using namespace std;

int digitFreq(int n, int k)
{
    int freq = 0;
    while (n > 0)
    {
        if (n % 10 == k)
        {
            freq++;
        }
        n = n / 10;
    }
    return freq;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << digitFreq(n, k) << endl;
}