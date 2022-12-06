//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll int
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;

class Solution{
	public:
	int LongestBitonicSequence(vector<int> v)
	{
	    
	    if(v.size() <= 2){
	        return v.size();
	    }
	    
	    int ans = 0,n=v.size();
        vector<ll> p_inc(n,0);
        vector<ll> p_dec(n,0);
        
        p_inc[0] = 0;
        for(ll i = 1;i<n;++i){
            ll lft = -1,rgt = 0;
            for(ll j = i-1;j>=0;--j){
                if(v[i] > v[j]){lft = max(max(0,lft),p_inc[j]);}
            }
            p_inc[i] = (lft+1);
        }

        p_dec[n-1] = 0;
        for(int i = n-2;i>=0;--i){
            ll lft = -1,rgt = 0;
            for(ll j = i+1;j<n;++j){
                if(v[i] > v[j]){lft = max(max(0,lft),p_dec[j]);}
            }
            p_dec[i] = (lft+1);
        }
        
        for(ll i = 0;i<n;++i){
            ans = max(ans,p_inc[i]+p_dec[i]+1);
        }
        return ans;  
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends