#include <iostream>
using namespace std;
int power(long long x, int y, int p)
{
    int sum = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            sum = (sum*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return sum;
}
int main()
{  int n,t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    cin>>n;
    int p =1000000007;
    cout<< power(2, n-1, p)<<"\n";
    }
    return 0;
}
