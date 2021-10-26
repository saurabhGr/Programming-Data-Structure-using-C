#include <iostream>
#include<cmath>
#include<math.h>
using namespace std;

float sincl(float n)
{
    float accuracy = 0.0001, denominator, sinx, sinval, temp;
    int i=1;
    // 1stly converting degree to redian
    n = n * (3.142 / 180.0);
    temp = n;

    //It is used for mapping the sum along the series
    sinx = n;
    // sinval is used for storing the value of sin(n)
    sinval = sin(n);
    do
    {
        denominator = 2 * i * (2 * i + 1);
        temp = -temp * n * n / denominator;
        sinx = sinx + temp;
        i = i + 1;
    } while (accuracy <= fabs(sinval - sinx));
    return sinx;
}

//for doing pow(x,5), i used pow() function available in c++ cmath header file
//for doing log(x), i used pow() function available in c++ cmath header file

int main()
{ cout<<"Enter value of x: "<<endl;
   float x;
   cin>>x;
   float f; // to store final result
   float first; // used to store calculation done by sincl(x)
   first=sincl(x);
   float second; // used to store result of pow(x,5)
   second=pow(x,5);
   float third; //used to store calculation done by log(x)
   third=log(x);
   float fourth; // used for storing result of x/4
   fourth=x/4;
   float fifth; // used to store result of substraction of first and second
   fifth=first-second;
   float sixth; //used to store result of addition of third and fourth
   sixth=third+fourth;
   float seventh; //it used to store result of divison of fifth and sixth
   seventh=fifth/sixth;
   float eighth; // it is used to store result of sqrt() of seventh
   eighth=sqrt(seventh);
   cout<<"sin(x)="<<first<<"\n"<<"pow(x,5)="<<second<<"\n";
   cout<<"log(x)="<<third<<"\n"<<"x/4="<<fourth<<"\n";
   cout<<"(sin(x)-pow(x,5))="<<fifth<<"\n"<<"(log(x)+x/4)="<<"\n";
   cout<<"(sin(x)-pow(x,5))/(log(x)+x/4)="<<sixth<<"\n";
   cout<<"sqrt((sin(x)-pow(x,5))/(log(x)+x/4))="<<seventh<<endl;
   cout<<"Final value is:"<<eighth<<endl;

   f=sqrt(((first-second))/ (log(x)+x/4)); //as power term became very big so, when it is subtracted from sin(x)
                                                              //its value become negative show we are not getting square root value
   cout<<f;
    return 0;
}
