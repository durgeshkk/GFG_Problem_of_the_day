//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

#define ll int
class Solution {
  public:
    string BalancedString(int n) {
        // code here
        string ans;

        ll dig_sm = 0,m = n;
        while(m != 0){
            dig_sm += (m%10);
            m /= 10;
        }

        if(n > 26){
            string tmp;
            for(ll i = 0;i<26;++i){
                tmp += ('a'+i);
            }
            ll cnt = n/26;
            n -= (26*cnt);

            while(cnt--){
                ans += tmp;
            }
        }
        
        if(n & 1){
            ll beg,end;
            string b,e;

            if(dig_sm & 1){
                end = ceil(1.0*n/2),beg = n/2;
            }else{
                beg = ceil(1.0*n/2),end = n/2;
            }
            for(ll i = 0;i<beg;++i){
                b += ('a'+i);
            }
            
            for(ll i = 0;i<end;++i){
                e += ('z'-i);
            }
            sort(e.begin(),e.end());
            ans += b;
            ans += e;
        }else{
            ll beg,end;
            string b,e;
            beg = ceil(1.0*n/2),end = n/2;
            for(ll i = 0;i<beg;++i){
                b += ('a'+i);
            }
            
            for(ll i = 0;i<end;++i){
                e += ('z'-i);
            }
            sort(e.begin(),e.end());
            ans += b;
            ans += e;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends