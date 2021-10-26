#include <iostream>

using namespace std;

int main()
{ int X,A,B,T,result;
    cin>>T;
    if(T>=1&&T<=1000)
   {for(int i=1;i<=T;i++)
   {
       cin>>X>>A>>B;
       if((X>=31&&X<=40) &&(A>=101&&A<=120) &&(B>=1&&B<=5))
          {result=(A+(100-X)*B)*10;
           cout<<result<<endl;
          }
        else return 0;
   }
   }
    return 0;
}
