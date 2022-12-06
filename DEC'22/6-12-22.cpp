//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll int
// } Driver Code Ends
class Solution 
{
    public:

    bool isValid(ll i,ll j,ll n,ll m){
        if(i<0 || j<0 || j>=m || i>=n){return false;}
        return true;
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>> nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(),m = grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
	    vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<ll,ll>> q;
        for(ll i=0;i<n;++i){
            for(ll j=0;j<m;++j){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j]=1;
                    ans[i][j] = 0;
                }
            }
        }

        int level = 0;
        while(!q.empty()){
            ll sz = q.size();
            for(ll i = 0;i<sz;++i){
                auto p = q.front();
                q.pop();

                // if not visited push all neighbours of p to Q
                ll x = p.first,y = p.second;
                
                // Down Valid
                if(isValid(p.first+1,p.second,n,m) and (!vis[x+1][y])){
                    q.push({p.first+1,p.second});
                    ans[x+1][y] = level+1;
                    vis[x+1][y] = 1;
                }

                // Up Valid
                if(isValid(p.first-1,p.second,n,m) and (!vis[x-1][y])){
                    q.push({p.first-1,p.second});
                    ans[x-1][y] = level+1;
                    vis[x-1][y] = 1;
                }

                // Left Valid
                if(isValid(p.first,p.second-1,n,m) and (!vis[x][y-1])){
                    q.push({p.first,p.second-1});
                    ans[x][y-1] = level+1;
                    vis[x][y-1] = 1;
                }
                
                // Right Valid
                if(isValid(p.first,p.second+1,n,m) and (!vis[x][y+1])){
                    q.push({p.first,p.second+1});
                    ans[x][y+1] = level+1;
                    vis[x][y+1] = 1;
                }
            }
            // Mark ans as level+1
            ++level;
        }
        /*
	    set<pair<ll,ll>> s;
        for(ll i=0;i<n;++i){
            for(ll j=0;j<m;++j){
                if(grid[i][j] == 1){
                    s.insert({i,j});
                }
            }
        }

        for(ll i=0;i<n;++i){
            for(ll j=0;j<m;++j){
                if(grid[i][j] == 1){ans[i][j] = 0;}
                ll val = INT_MAX;
                for(auto it:s){
                    int z = abs(it.first-i)+abs(it.second-j);
                    val = min(val,z);
                }
                ans[i][j] = val;
            }
        }*/
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
    /*
    vector<vector<int>>grid(500, vector<int>(500, 0));
        // for(auto i: grid){
		// 	for(auto j: i){
		// 		cout << j << " ";
		// 	}
		// 	cout << "\n";
		// }

        Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}*/
    // /*
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
    // */
	return 0;
}
// } Driver Code Ends