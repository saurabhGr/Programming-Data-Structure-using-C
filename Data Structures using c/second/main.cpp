#include <iostream>

using namespace std;

int main()
{
    cout << "Enter number" << endl;
    int n;
    int sum=0;
    cin>>n;
    while(n>0)
    { if(n%2==0)
        sum=sum+n;
        n--;
    }
    cout<<sum<<endl;
    return 0;
}
