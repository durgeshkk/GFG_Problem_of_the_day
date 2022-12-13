//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
#define ll int
class Solution {
  public:
    ll helper(int v[] ,int n, int k){

        ll mx = 0,mxval = 0;
        for(ll i=0;i<n;++i){
            mx = max(mx,v[i]); 
            mxval += v[i];
        }

        ll l = mx,r = mxval,ans = 0,dynamo = 0;
        // ans will store sum for given range!!
        while(l <= r){
            ll mid = (l+r)/2;
            // mid is the values which is telling if we can divide the subarray
            // with the value as mid or not
            ll sbarr = 1,sm = 0;
            for(ll i=0;i<n;++i){
                sm += v[i];
                if(sm > mid){
                    ++sbarr;
                    sm = v[i];
                }
            }

            if(sbarr > k){
                l = mid+1;
            }else{
                dynamo = mid;
                r = mid-1;
            }
        }

        return dynamo;
    }


    int splitArray(int arr[] ,int n, int k) {
        // code here
        // Binary Search for ans value & then apply for loop within the BS 
        // to check if given mid value satisfy the constraint of k
        ll ans = helper(arr,n,k);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends