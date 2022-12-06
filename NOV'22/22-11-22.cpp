#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
using namespace std;
ll mod = (ll)(1e9+7);
 
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution{
	public:
	int countTriplets(vector<int> v){
	    // Code here.
	    int ans = 0,n = v.size();
        ordered_set os;
        vector<int> small;
        vector<int> big(n,0);
    
        for(int i = 0;i<n;++i){
            os.insert(v[i]);
            ll idx = os.order_of_key(v[i]);
            small.push_back(idx);
        }
        os.clear();
    
    
        map<ll,ll> mp;
        ll sz = 0;
        for(int i = n-1;i>=0;--i){
            os.insert(v[i]);
            mp[v[i]]++;
            
            if(mp[v[i]] > 1){
                ++sz;
            }
            
            ll idx = os.order_of_key(v[i]);
            idx = os.size()-idx-mp[v[i]];
            big[i] = idx;
        }
        
        // show(small);
        // show(big);
        
        for(int i = 1;i<n-1;++i){
            ans += (small[i]*big[i]);
        }
	    return ans;
	}
};

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);
 
    
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}