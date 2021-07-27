#include <iostream>
using namespace std;

int substract(int n, int m, int base)
{
    int ans=0,carry=0,y=1;
    while(n>0){
        int ldn=n%10;
        n=n/10;
        int ldm=m%10;
        m=m/10;
        ldn=ldn+carry;
        int calc=0;
        if(ldm>ldn){
            carry=-1;
            calc=ldn+base-ldm;
        }else{
            carry=0;
            calc=ldn-ldm;
        }
        ans=ans+ calc*y;
        y=y*10;
    }return ans;
}

int main()
{
    int n, m, base;
    cin >> n >> m >> base;
    cout <<substract(n, m, base);
}