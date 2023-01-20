//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++
#define ll long long int
class Solution {
public:
    int minimizeSum(int n, vector<int> arr) {
        // code here
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(ll i = 0;i<n;++i){
            pq.push(arr[i]);
        }

        ll ans = 0;
        while(pq.size() > 1){
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            ll sm = (a+b);
            pq.push(sm);
            ans += sm;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends