//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#define ll int

class Solution {
  public:

    // 2 D DP : 
    /*
    map<pair<ll,ll>,ll> dp;

    ll recur(int i,int v[],int n,int mx){
        if(i >= n){
            return 0;
        }

        if(dp.find({i,mx}) != dp.end()){
            return dp[{i,mx}];
        }

        ll a=0,b=0,c = 0;
        if(v[i] > mx){
            // Pick
            a = 1+recur(i+1,v,n,v[i]);

            // Not Pick
            b = recur(i+1,v,n,mx);
        }else{
            // Not Pick
            c = recur(i+1,v,n,mx);
        }

        return dp[{i,mx}] = max({a,b,c});
    }*/

    vector<ll> dp;
    ll recur(ll v[],ll n){
        dp.push_back(v[0]);

        for(ll i = 1;i<n;++i){
            if(v[i] > dp[dp.size()-1]){
                dp.push_back(v[i]);
            }

            ll idx = lower_bound(dp.begin(),dp.end(),v[i])-dp.begin();
            dp[idx] = v[i];
        }

        return dp.size();
    }

    int removeStudents(int H[], int N) {
        // code here
        // Find max increasing subsequence
        // ll ans = recur(0,H,N,0);
        ll ans = recur(H,N);
        return (N-ans);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends