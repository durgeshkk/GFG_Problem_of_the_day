//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define ll long long
class Solution {
  public:
  
    ll gcd(ll a, ll b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    
    ll solve(int n){
        ll ans = n;
        ll cnt = 1;
        for(ll i = n-1;i>0;--i){
            ll val = gcd(i,ans);
            if(val == 1){
                ans *= i;++cnt;
            }
            if(cnt == 4){return ans;}
        }
        return ans;
    }
  
    long long maxGcd(int n) {
        // code here
        ll ans1 = solve(n);
        ll ans2 = solve(n-1);
        return max(ans1,ans2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends