//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends

#define ll int
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        int mx = INT_MIN,mn = INT_MAX;
        ll ans = INT_MIN;
        
        // i <= j, so opening goes as
        // ans = | (arr[i]-arr[j]) | + (j-i)
        // Now, open arr[i]-arr[j] wisely ...
        // Case 1 : + opening : (arr[i]-i)-(arr[j]-j)
        // Case 2 : - opening : (arr[j]+j)-(arr[i]+i)

        for(ll i = 0;i<n;++i){
            ll val = (arr[i]+i);
            mn = min(mn,val);
            ll a = val-mn;
            
            val = (arr[i]-i);
            mx = max(mx,val);
            ll b = mx-val;
            
            ans = max(ans,max(a,b));
        }
        return ans;
    } 

};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends