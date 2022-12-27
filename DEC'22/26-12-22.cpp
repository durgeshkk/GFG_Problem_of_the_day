//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
#define ll long long int
class Solution{
public:
    vector<ll> v;
    void precompute()
    {
        // Code Here
        // Very wrong approach, a loop can't run
        // more than 1e8 times

        for(ll i = 0;i<63;++i){
            for(ll j = i+1;j<63;++j){
                for(ll k = j+1;k<63;++k){
                    ll sm = pow(2,i) + pow(2,j) + pow(2,k);
                    v.push_back(sm);
                }
            }
        }
        sort(v.begin(),v.end());
        /*
        for(ll i = 1;i<=(ll)1e18;++i){
            ll cnt = 0;
            bitset<64> s(i);
            for(ll j = 0;j<64;++j){
                if(s[j] == 1){++cnt;}
            }

            if(cnt == 3){
                v.push_back(i);
            }
        }
        */
    }
    
    long long solve(long long l, long long r){
        // Code Here
        ll low = lower_bound(v.begin(),v.end(),l)-v.begin();
        ll high = lower_bound(v.begin(),v.end(),r+1)-v.begin();
        
        if(v[high] != r){
            --high;
        }
        ll ans = (high-low);
        return (ans+1);
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends