//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

#define ll int
class Solution {
  public:
    int minOperation(string s) {
        // code here
        ll n = s.size(),ans = n;
        for(ll i = 0;i<n;++i){
            // Consider the substr till i
            string tmp = s.substr(0,i+1);
            // Replication work
            ll len = tmp.size();
            string st = tmp;

            ll op = (i+1);
            string prev = st;
            st += st;
            string ak = s.substr(0,st.size());
            if(ak == st){
                ++op;
                prev = st;
            }else{
                prev = tmp;
            }
            
            op += (n-prev.size());
            ans = min(ans,op);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends