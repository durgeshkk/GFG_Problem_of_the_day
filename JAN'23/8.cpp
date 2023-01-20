//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#define ll long long int
class Solution {
  public:
  /*
  long long countPairs(int n, int arr[], int k) {
        // code here
        unordered_map<ll,ll> mp;
        ll ans = 0;
        for(ll i = 0;i<n;++i){
            ll sm = (arr[i]%k);
            ans += mp[sm];
            mp[sm]++;
        }
        return ans;
    }
  */
    long long countPairs(int n, int arr[], int k) {
        // code here
        ll ans = 0;
        map<ll,ll> mp;
        for(ll i = 0;i<n;++i){
            ll sm = (arr[i]%k);
            mp[arr[i]%k]++;
            // mp[arr[i]]++;
        }

        for(auto it:mp){
            ll sm = it.second*(it.second-1)/2;
            ans += sm;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends