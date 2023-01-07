//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define ll int 
class Solution{   
  public:

    void primes(vector<int>&v){
        for(int i=2;i*i<10000;i++){
           if(v[i] == 1){
               for(ll j=i*i;j<10000;j+=i){
                   v[j]=0;
               }
           }
       }
    }

    int shortestPath(int a,int b)
    {   
        // Complete this function using prime vector
        vector<int>v(10000,1);
        primes(v);
        
        queue<pair<ll,ll>> q;
        map<ll,ll> mp;
        q.push({a,0});
        mp[a]++;

        while(!q.empty()){
            ll n=q.size();
            while(n--){
                auto it=q.front();
                q.pop();
                ll f = it.first, sec = it.second;
            
                if(f == b){
                    return sec;
                }

                string s=to_string(f);
                for(ll i=0;i<4;++i){
                    string st=s;
                    for(ll j = 0;j<=9;j++){
                        if(j == 0 && i == 0){
                            continue;
                        }else{
                            st[i]=(j+'0');
                            ll tmp = stoll(st);
                            
                            if(mp[tmp]==0 && tmp != f && v[tmp]){
                                mp[tmp]++;
                                q.push({tmp,sec+1});
                            }
                        }
                    }
                }

            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    ll t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll answer=obj.shortestPath(a,b);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends