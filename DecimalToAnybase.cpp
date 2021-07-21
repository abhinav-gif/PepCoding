#include <iostream>
#include<cmath>
using namespace std;

int convert(int num, int base)
{
    int ans = 0, y = 0;
    while (num > 0)
    {
        int temp = num % base;
        ans = ans + temp * pow(10, y);
        y++;
        num = num / base;
    }
    return ans;
}

int main()
{
    //Decimal Number
    int n, b;
    cin >> n >> b;
    cout << convert(n, b) << endl;
}