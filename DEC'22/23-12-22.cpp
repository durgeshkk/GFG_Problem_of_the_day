//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

#define ll int
// } Driver Code Ends
class Solution {
public:
    vector<vector<ll>> dp;
    ll solve(ll i,ll j,vector<ll> &v){
        if(i > j){return 0;}

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        ll mx = INT_MIN;
        for(ll k = i;k<=j;++k){
            ll smallcalc = (v[k]*v[i-1]*v[j+1]);
            ll smallans = solve(i,k-1,v)+solve(k+1,j,v)+smallcalc;
            mx = max(mx,smallans);
        }

        return (dp[i][j] = mx);
    }

    int maxCoins(int n, vector<int> &v) {
        // code here
        // Agar samne se sochenge toh it will be a lot tough to think ki konsa baloon
        // pehle fodde aur fir harr stage pe jb hum divide krne jayenge toh confuse
        // honge ki abb konsa fodna h aur aage aksie badna h!!
        // Thus the easiest way to solve such kind of prblm is to think ki hum ek ith
        // baloon ko last mein fodd rhe h aur usse bolenge tere left aur right ka 
        // ans le aa..
        // ans = leftsmallans + rightsmallans + arr[k]*arr[left_ele]*arr[right_ele]

        // e.g. :i, ,k, , ,j,
        // e.g. : ,3,1,5,8, 
        // Assume kth baloon 1 is bursted at last!!
        // ans = ans[i,k-1]+ans[k+1,j]+(small calc.)
        // smallcalc. = (arr[i]*arr[k]*arr[j]);
        // Last balloon 1 to n koi bhi ho sakta h thus, need to loop from 1 to n(i idx)
        n = v.size();
        v.push_back(1);
        v.insert(v.begin()+0,1);
        dp.assign(n+2,vector<ll> (n+2,-1));
        ll ans = solve(1,n,v);
        return ans; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends