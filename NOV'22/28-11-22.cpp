//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++

#define ll int
#define pb push_back
class Solution{
public:
	vector<int> findSubarray(int v[], int n) {
	    ll l = -1, r = -1, mxlen = -1, len = 0, mxsm = 0,sm = 0;
	    ll sl = -1,sr = -1;ll f = 0;
	    
	    for(int i = 0;i<n;++i){
	        if(v[i] < 0){
	            if(mxsm < sm){
	                mxsm = sm;
	                l = sl,r = sr;
	                len = 0;
	            }else if(mxsm == sm){
	                if(len > mxlen){
	                    l = sl;
	                    r = sr;
	                    mxlen = len;len = 0;
	                }
	            }
	            sm = 0;
	            f = 0;
	        }else{
	            if(f == 0){
	                f = 1;
	                sl = i;sr = i;
	            }
	            sr = i;
	            sm += v[i];
	            ++len;
	        }
	    }
	    
	    if(mxsm < sm){
	        mxsm = sm;
	        l = sl,r = sr;
	    }else if(mxsm == sm){
	        if(len > mxlen){
	            l = sl;
	            r = sr;
	            mxlen = len;
	        }
	    }
	        
	    vector<ll> ans;
	    if((l == -1) and (r == -1)){
	        ans.pb(-1);
	        return ans;
	    }
	    
	   // cout<<l<<" "<<r<<endl;
	    for(ll i = l;i<=r;++i){
	        ans.pb(v[i]);
	    }    
	    
	    
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
