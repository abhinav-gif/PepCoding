#include <iostream>
using namespace std;

int add(int n, int m, int base)
{
    int carry = 0;
    int ans = 0, y = 1;
    while (n > 0 || m > 0||carry>0)
    {
        int ldn = n % 10;
        int ldm = m % 10;
        int sum = carry + ldn + ldm;
        carry = sum / base;
        sum = sum % base;
        ans = ans + sum * y;
        y = y * 10;
        n = n / 10;
        m = m / 10;
    }
    return ans;
}

int main()
{
    int n, m, base;
    cin >> n >> m >> base;
    cout <<add(n, m, base);
}