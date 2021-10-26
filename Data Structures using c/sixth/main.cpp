#include <iostream>

using namespace std;

int main()
{
    cout << "Number of rows" << endl;
    int n,i,j;
    char y,x='A';
    cin>>n;
    for(i=1,x='A';i<=n;i++,x++)
    {
        for(j=1,y=x;j<=i;j++,y++)
                cout<<y;
        cout<<endl;
    }
    return 0;
}
