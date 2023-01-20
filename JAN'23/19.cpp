//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#define ll int
class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
         ll mn = min(A, B),mx = max(A, B),ans = 0;
         while (!(mx <= max(C, D))) {
            mx /= 2;
            if(mx<mn){
                swap(mx,mn);
            }
            ++ans;
        }

        while (!(mn <= min(C,D))){
            mn /= 2;
            ++ans;
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends