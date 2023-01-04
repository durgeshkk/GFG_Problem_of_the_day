//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define ll int
class Solution {
  public:
    vector<ll> dp;
    ll rec(ll n,auto &it,auto &v,ll i){
        if(i == n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        ll idx = lower_bound(v.begin(),v.end(),it[i][1])-v.begin();
        ll smallans = rec(n,it,v,idx,dp);
        ll left = it[i][2] + smallans;

        smallans = rec(n,it,v,i+1,dp);
        return dp[i] = max(left,smallans);
    }

    int maximum_profit(int n, vector<vector<int>> &intervals) {
        sort(intervals.begin(),intervals.end());
        vector<ll>v;
        vector<ll>dp(n+1,-1);

        for(auto it:intervals){
            v.push_back(it[0]);
        }

        return rec(n,intervals,v,0);

    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends