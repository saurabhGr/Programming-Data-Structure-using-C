// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function Template for C++
class Solution {
  public:
    long long makeItOne(long long N){
        // code here
        int i,count=0,val;
        for(i=0;i<N;i++)
        { val=pow(2,i);
           if(val==N)
           {N=N/2;
           i=0;
           count++;}
           else if(val>N)
                 {val=pow(2,i-1);
                 N=N-val;
                 count++;
                 i=0;}
        if(N==1)
         {
            break;
         }
        }

    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution obj;
        long long ans = obj.makeItOne(N);
        cout << ans <<'\n';
    }
    return 0;
}  // } Driver Code Ends
