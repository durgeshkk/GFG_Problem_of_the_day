#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

int longestPerfectPiece(int v[], int n) {
    // code here
    multiset<int> ms;
    int ag = 0;
    int j = 0;
    for(int i = 0;i<n ;++i){
        ms.insert(v[i]);
        int mx = *ms.rbegin();
        int mn = *ms.begin();
        while(mx - mn >1){
            ms.erase(ms.find(v[j]));
            mx = *ms.rbegin();
            mn = *ms.begin();
            ++j;
        }
        ag = max(ag,(int)ms.size());
    }
    return ag;
    
    
    
    
    // Brute force:
    /*
    int mx = INT_MIN,mn = INT_MAX;
    
    for(int i = 0;i<n;++i){
        mx = v[i],mn = v[i];
        int j = (i);
        while((mx-mn <= 1) and (j < n)){
            mn = min(mn,v[j]);
            mx = max(mx,v[j]);
            if(mx-mn > 1){
                break;
            }
            
            // cout<<j<<" ";
            ag = max(ag,j-i+1);
            ++j;
        }
        // cout<<endl;
    }
    return ag;*/
    
    
    /*
        int j = 0,ans = 0;
        
        map<int,int> mp;
    for(int i = 0;i<n;++i){
        mx = max(mx,v[i]);
        mn = min(mn,v[i]);
        mp[v[i]]++;
        
        if(mx-mn <= 1){
            ans = max(ans,i-j);
        }else{
            while(mp[mn] != 0){
                ++j;
                mp[v[i]]--;
            }
        }
    }*/
    
    
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);
 
    //for(ll i=0;i<n;i++){
       //cin>>v[i];
    //}
 
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
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