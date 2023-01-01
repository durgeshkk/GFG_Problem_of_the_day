//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll mod = (ll)(1e9+7);
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

class Solution{
	public:

    ll inv(ll r){
	    if(r==1){
            return 1;
        } 
	    return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
	}

    int compute_value(int n)
	{
	    // Code here
        ll ans = 1,val=1;
	    for(int i=1; i<=n; i++){
	        val = (((val*(n+1-i))%mod)*inv(i))%mod;
	        ans = (ans+(val*val)%mod)%mod;
	    }
	    return ans%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends

