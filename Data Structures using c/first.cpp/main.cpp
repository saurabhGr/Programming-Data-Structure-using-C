#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a charecter" << endl;
    char i;
    cin>>i;
    int j=i;
    if(j>=65&&j<=90)
        cout<<"1"<<endl;
    else if(j>=97&&j<=122)
               cout<<"0"<<endl;
    else cout<<"-1"<<endl;
    return 0;
}
