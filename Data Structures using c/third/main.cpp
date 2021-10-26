#include <iostream>

using namespace std;

int main()
{
    cout << "Enter value of S E W" << endl;
    int s,e,w,cel;
    cin>>s>>e>>w;
    while(s<=e)
    {
        cel=(5*(s-32))/9;
        cout<<s<<"\t"<<cel<<endl;
        s=s+w;
    }
    return 0;
}
