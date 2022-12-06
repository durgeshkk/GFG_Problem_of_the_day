//{ Driver Code Starts
#include <bits/stdc++.h>
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;

// } Driver Code Ends

#define ll long long int
ll mod = (ll)(1e9+7);

class Solution{
public:
    
    const ll N = 1e5+1;
    long long int numoffbt(long long int v[], int n){
        ll ans = 0;
        vector<ll> dp(25,0);
        ll mx = LLONG_MIN, mn = LLONG_MAX;
        
        for(ll i = 0;i<n;++i){
            mn = min(mn,v[i]);
            mx = max(mx,v[i]);
            dp[v[i]] = 1;
        }
        
        for(ll i = mn;i<=mx;++i){
            if(dp[i] == 1){
                
                for(ll j = mn;j*j <= i;++j){
                    if(i%j == 0){
                        ll fact = i/j;
                        if(dp[fact] != 0 and dp[j] != 0){
                            if(fact != j){
                                dp[i] += 2*(dp[fact]*dp[j]);
                            }else{
                                dp[i] += dp[j]*dp[j];
                            }
                        }
                    }
                }
                
                ans = dp[i]+ans;
                ans = ans%mod;
            }
        }
        // show(dp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends