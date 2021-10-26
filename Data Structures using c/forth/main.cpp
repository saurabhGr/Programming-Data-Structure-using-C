#include <iostream>

using namespace std;

int main()
{
    cout << "Number of rows" << endl;
    int n,i,j,k=1,l;
    cin>>n;
    for(i=1;i<=n;i++)
    {  for(l=1;l<=n-i;l++)
            cout<<" ";
        for(j=1;j<=i;j++,k++)
            cout<<k;
        cout<<endl;
    }
    return 0;
}
