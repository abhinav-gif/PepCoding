#include <iostream>
#include <cmath>
using namespace std;

int getValueInDecimal(int num, int base)
{
    int ans = 0, p = 1;
    while (num > 0)
    {
        int temp = num % 10;
        ans = ans + temp * p;
        p = p * base;
        num = num / 10;
    }
    return ans;
}

int decimalToAny(int num, int base)
{
    int ans = 0, p = 1;
    while (num > 0)
    {
        int temp = num % base;
        ans = ans + temp * p;
        p = p * 10;
        num = num / base;
    }
    return ans;
}

int convert(int n, int b1, int b2)
{
    int decimal = getValueInDecimal(n, b1);
    return decimalToAny(decimal, b2);
}

int main()
{
    int n, b1, b2;
    cin >> n >> b1 >> b2;
    cout << "Base " << b1 << " To "
         << "Base " << b2 << endl
         << convert(n, b1, b2) << endl;
}