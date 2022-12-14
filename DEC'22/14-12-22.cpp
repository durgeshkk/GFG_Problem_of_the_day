//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;

// } Driver Code Ends
#define ll int
class Solution{
public:
// Wrong Q interpretation :
    vector<int> findRange(string s, int n) {
        // code here
        vector<int> v;
        for(ll i = 0;i<n;++i){
            if(s[i] == '0'){
                v.push_back(1);
            }else{
                v.push_back(-1);
            }
        }

        // show(v);

        ll sm = 0,mx = 0;
        ll l = -1,r = -1,idx = -1;
        for(ll i = 0;i<n;++i){
            sm += v[i];
            if(sm < 0){
                sm = 0;
                idx = i;
            }else if(mx < sm){
                mx = sm;l = idx+1;
                r = i;
            }
        }

        if(mx < sm){
            mx = sm;l = idx;
            r = (n-1);
        }

    /*
        for(ll i = 0;i<n;++i){
            if(s[i] == '0'){
                ll cnt = 1,idx = i;
                while(s[i] == '0'){
                    ++i,++cnt;
                }

                if((cnt) > len){
                    l = idx+1,r = i;
                    len = (cnt);
                }
            }
        }
    */
        if(l == -1){
            return {-1};
        }else{
            return {l+1,r+1};
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends