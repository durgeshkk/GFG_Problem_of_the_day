//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#define ll int
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    
    // ll steps = ll_MAX;
    // ll z = ll_MAX; 
    // Recursion :
    /*
    void recur(vector<vector<ll>> &mat,vector<vector<ll>> &dp,vector<vector<ll>> &vis, ll n, ll m, ll i, ll j, ll cnt, ll steps,ll k){
    
        if(i >= n || j >= m || i<0 || j<0){
            return;
        }   
    
        if(vis[i][j]){return;}
    
        // cout<<i<<" "<<j<<" "<<cnt<<endl;
        vis[i][j] = 1;
    
        // if(vis[i][j] == 1){
        //     cout<<"HI\n";
        //     return;
        // }
        
        if(i == (n-1) and j == (m-1)){
            if(cnt > k){
            
            }else{
                // cout<<"HI\n";
                z = min(z,cnt);
                steps = min(steps,steps);
            }
        }
    
    
        // Up 
        if(i-1 >= 0){
            // vis[i-1][j] = 1;
            if(mat[i-1][j] == 1){++cnt;}
            recur(mat,dp,vis,n,m,i-1,j,cnt,steps+1,k);
            // vis[i-1][j] = 0;
        }
        // Down
        if(i+1 < n){
            // vis[i+1][j] = 1;
            if(mat[i+1][j] == 1){++cnt;}
            recur(mat,dp,vis,n,m,i+1,j,cnt,steps+1,k);
            // vis[i+1][j] = 0;
        }
    
        // Left
        if(j-1 >= 0){
            if(mat[i][j-1] == 1){++cnt;}
            recur(mat,dp,vis,n,m,i,j-1,cnt,steps+1,k);
            // vis[i][j-1] = 1;
            // vis[i][j-1] = 0;
        }
    
        // Right
        if(j+1 < m){
            // vis[i][j+1] = 1;
            if(mat[i][j+1] == 1){++cnt;}
            recur(mat,dp,vis,n,m,i,j+1,cnt,steps+1,k);
            // vis[i][j+1] = 0;
        }
        vis[i][j] = 0;
        return;
    }*/

    bool isValid(ll i,ll j,ll n,ll m){
        if(i >= n || j >= m || i<0 || j<0){
            return false;
        } return true;
    }

    ll shotestPath(vector<vector<ll>> &mat, ll n, ll m, ll k) {
        // code here
        // Check all the paths, get the path with min. no. of diwar to reach the 
        // destiny.
        // If this min. >= k return yes else no
        // else steps = min(steps,no. of steps req to reach destiny by this path);

        // *** SHORTEST PATH ==> BFS
        // queue must have {x_pos,y_pos, no. of obstacles we can destroy}
        
        vector<vector<vector<ll>>>vis(n,vector<vector<ll>>(m,vector<ll>(k+1,0)));
        queue<vector<ll>>q;
        q.push({0,0,k});
        vis[0][0][k] = 1;
        // up,right,down,left
        ll dx[4] = {-1,0,1, 0};
        ll dy[4] = {0 ,1,0,-1};
        ll steps = 0;

        while(!q.empty()){
            ll sz = q.size();
            for(ll i=0;i<sz;i++){
                auto v = q.front();
                q.pop();
                ll x = v[0],y = v[1],diwar = v[2];

                if(x==n-1 && y==m-1) return steps;

                for(ll j=0;j<4;j++){
                    ll nx = x+dx[j];
                    ll ny = y+dy[j];

                    // Checking Boundary
                    if(isValid(nx,ny,n,m)){
                        if(mat[nx][ny]==0 && vis[nx][ny][diwar]==0){
                            vis[nx][ny][diwar] = 1;
                            q.push({nx,ny,diwar});
                        }
                        else if(mat[nx][ny]==1 && diwar>0 && vis[nx][ny][diwar-1]==0){
                           vis[nx][ny][diwar-1] = 1;
                           q.push({nx,ny,diwar-1});
                        }
                    }
                }
            }
            steps++;
          }

         return -1;
        
        /*
        ll steps = 0;
        queue<vector<ll>> q;
        vector<vector<ll>> obs(n,vector<ll> (m,ll_MAX));
        const vector<vector<ll>> direxn = {{1,0},{0,1},{-1,0},{1,0}};
        obs[0][0] = mat[0][0];
        q.push({0,0});

        while(!q.empty()){

            for(ll l = q.size();l>0;--l){
                auto p = q.front();
                ll i = p[0],j=p[1];
                q.pop();

                // if curr_x == n-1 & curr_y == m-1 return steps;
                if(i == n-1 and j == m-1){return steps;}

                // Explore this pop cell in all 4-direxns if not explored...& mark as vis
                for(auto &it:direxn){
                    ll x = i+it[0];
                    ll y = j+it[1];
                    if(x >= n || y >= m || x<0 || y<0){
                        continue;
                    }
                    // Only remove k diwar
                    if(mat[x][y] + obs[i][j] > k){
                        continue;
                    }
                    // If already vis
                    if((mat[x][y] + obs[i][j]) >= obs[x][y]){
                        continue;
                    }

                    obs[x][y] = mat[x][y] + obs[i][j];
                    q.push({x,y});
                }
            }

            // Update steps
            steps++;
        }
        return -1;*/
        // DFS :
        /*
        vector<vector<ll>> vis(n,vector<ll> (m,0));
        vector<vector<ll>> dp(n,vector<ll> (m,0));

        recur(mat,dp,vis,n,m,0,0,0,0,k);
        if(steps == ll_MAX){
            steps = -1;
        }
        return steps;*/
    }
};

//{ Driver Code Starts.

int main() {
    ll t=1;
    // cin >> t;
    while (t--) {
        ll n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<ll>> mat;
    
        for(ll i=0; i<n; i++)
        {
            vector<ll> row;
            for(ll j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends