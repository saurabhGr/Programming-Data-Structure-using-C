#include <iostream>

using namespace std;

int main()
{
    cout << "Number of rows" << endl;
    int n,i,j,k=1,l;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(l=n-i;l>0;l--)
            cout<<" ";
        for(j=1;j<=(2*i)-1;j++)
                cout<<"*";
        for(l=n-i;l>0;l--)
            cout<<" ";
        cout<<endl;
    }
    return 0;
}
