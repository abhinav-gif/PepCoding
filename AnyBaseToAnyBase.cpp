#include <iostream>
#include <cmath>
using namespace std;

int convert(int n, int b1, int b2)
{
    int ans = 0, y = 0;
    while (n > 0)
    {
        int temp = n % b2;
        ans = ans + temp * pow(b1, y);
        y++;
        n = n / b2;
    }
    return ans;
}

int main()
{
    int n, b1, b2;
    cin >> n >> b1 >> b2;
    cout << "Base " << b1 << " To "
         << "Base " << b2 << endl
         << convert(n, b1, b2) << endl;
}