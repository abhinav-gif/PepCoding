#include <iostream>
#include<cmath>
using namespace std;

int convert(int num, int base)
{
    int ans = 0, p = 1;
    while (num > 0)
    {
        int temp = num % 10;
        ans = ans + temp * p;
        p=p*base;
        num = num / 10;
    }
    return ans;
}

int main()
{
    int n, b;
    cin >> n >> b;
    cout << convert(n, b) << endl;
}