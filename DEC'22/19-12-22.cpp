//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define ll long long int
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
class Solution {
  public:
    vector<ll> vis;

    ll bfs(ll i,vector<vector<vector<ll>>> &adj){
        queue<vector<ll>> q;
        q.push({i,0});

        while(!q.empty()){
            auto f = q.front();
            q.pop();

            ll node = f[0];
            ll cost = f[1];

            for(auto it:adj[node]){
                ll nx = it[0];
                ll cx = it[1];

                if(vis[nx] == -1){
                    vis[nx] = cost + cx;
                    q.push({nx,vis[nx]});
                }
                else if(vis[nx] > cost+cx){
                    vis[nx] = cost + cx;
                    q.push({nx,vis[nx]});
                }
            }
        }

        ll ans = LLONG_MIN;
        for(ll i = 1;i<vis.size();++i){
            if(vis[i] == -1){return -1;}
            ans = max(ans,vis[i]);
        }
        return ans;
    }
    /*
    ll dfs(ll i){
        vis[i] = 1;

        ll ans = 0;
        for(auto it:adj[i]){
            if(!vis[it]){
                ll val = dfs(it);
                val += mp[{i,it}];
                ans = max(ans,val);
            }
        }
        return ans;
    }
    */
    
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // Prerequisite :
        vector<vector<vector<ll>>> adj(n+1);
        vis.assign(n+1,-1);
        vis[k] = 0;

        // Here we go:
        for(ll i = 0;i<flights.size();++i){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        ll ans = bfs(k,adj);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends