//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define ll int
class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        ll cnta = 0,cntb = 0;
        bitset<32> s(a);
        for(ll i = 0;i<32;++i){
            if(s[i] == 1){++cnta;}
        }

        bitset<32> t(b);
        for(ll i = 0;i<32;++i){
            if(t[i] == 1){++cntb;}
        }

        ll x = 0;
        if(cnta > cntb){
            // Remove 1 in a from beginning
            for(ll i = 31;i>=0;--i){
                if(cntb == 0){break;}
                if(s[i] == 1){s[i] = 0;--cntb;}
            }
            x = s.to_ulong();
        }else if(cnta == cntb){
        }else{
            ll diff = (cntb-cnta);
            for(ll i = 0;i<32;++i){
                if(s[i] == 1){s[i] = 0;continue;}
                if(diff > 0){
                    if(s[i] == 0){s[i] = 1;--diff;}
                }
            }
            x = s.to_ulong();
        }
        x ^= a;
        return x;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends