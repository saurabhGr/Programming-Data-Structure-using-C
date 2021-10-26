#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t,n,x,hop,i;
    bool b;
    cin>>t;
    for(i=1;i<=t;i++)
    {
         cin>>n>>x>>hop;
         b=false;
        if(x%hop==0 ||(n+1-x)%hop==0)
        {
            cout<<"YES"<<"\n";
                b=true;
        }
        if(b==false)
            cout<<"NO"<<"\n";
    }
    return 0;
}
