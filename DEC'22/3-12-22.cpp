//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define ll int
class Solution {
public:

    int solve(int n, int k, vector<int> &v) {
        sort(v.begin(),v.end());
        ll l = 0,h = 1e9,ans = 0;
        while(l <= h){
            ll mid = (l+h)/2;
            ll cnt = 1,prev = v[0],diff = 0;
            // cout<<mid<<" ";

            for(ll i = 1;i<n;++i){
                if(v[i]-prev >= mid){
                    ++cnt;
                    prev = v[i];
                }
            }

            if(cnt >= k){
                ans = (mid);l = mid+1;
            }else{
                h = mid-1;
            }
            // cout<<l<<" "<<h<<" "<<ans<<endl;
        } 

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends