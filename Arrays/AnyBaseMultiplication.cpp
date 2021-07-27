#include <iostream>
using namespace std;
int add(int n, int m, int base)
{
    int carry = 0;
    int ans = 0, y = 1;
    while (n > 0 || m > 0 || carry > 0)
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

int multiply(int n, int m, int base)
{
    
    int finalans = 0, x = 1;
    while (m > 0)
    {   int carry = 0,y=1;
        int temp = n, ans = 0;
        while (temp > 0 || carry > 0)
        {
            int ldn = temp % 10;
            int ldm = m % 10;
            int sum = carry + (ldn * ldm);
            carry = sum / base;
            sum = sum % base;
            ans = ans + sum * y;
            y = y * 10;
            temp = temp / 10;
        }
        m = m / 10;
        finalans =add(finalans,ans*x,base);
            x = x * 10;
    }

    return finalans;
}

int main()
{
    int n, m, base;
    cin >> n >> m >> base;
    cout << multiply(n, m, base);
}