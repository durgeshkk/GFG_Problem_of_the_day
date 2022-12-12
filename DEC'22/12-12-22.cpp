//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define ll int
using namespace std;

// } Driver Code Ends
//User function Template for C++

// Graph Coloring + recur to detect no. of Cycles

vector<vector<int>> cycles;
void recur(vector<int> adj[],int i,int par,int color[],int p[],int &cycleno){

    if(color[i] == 2){
        return;
    }

    if(color[i] == 1){
        // Vertex not completely vis
        // But cycle detected
        vector<ll> v;
        ++cycleno;
        int curr = par;
        v.push_back(par);

        while(curr != i){
            curr = p[curr];
            v.push_back(curr);
        }
        cycles.push_back(v);
        return;
    }

    p[i] = par;
    color[i]  = 1;

    for (int j : adj[i]) {
 
        // if it has not been vis previously
        if (j == p[i]) {
            continue;
        }
        recur(adj,j,i,color,p,cycleno);
    }
 
    // completely vis.
    color[i] = 2;
}



class Solution {
  public:

    void recur(vector<int> adj[],vector<int> &ak,vector<int> &low,vector<int> &vis,int &akr,int par,int i,set<int> &s){ //i denotes the currnode
    
        ak[i]=low[i]=akr++;
        vis[i]=1;

        int child = 0;

        for(int it:adj[i]){
            if(it==par) continue;

            if(vis[it]==0){
                recur(adj,ak,low,vis,akr,i,it,s);
                low[i]=min(low[i],low[it]);

                if(low[it]>=ak[i] && par!=-1){
                    s.insert(i);
                }
                child++;
            }
            else{
                low[i]=min(low[i],low[it]);
            }
        }

        if(par==-1 && child>1){
            s.insert(i);
        }
    }

    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        int cycleno = 0;

        vector<int> Time(n,0),low(n,0),visited(n,0);
        int ak = 0;
        set<int> s;
        for(int i=0;i<n;i++){
            if(visited[i]==0) recur(adj,Time,low,visited,ak,-1,i,s);
        }

        vector<int> final(s.begin(),s.end());
        if(final.size() == 0) return {-1};
        return final;


        // Min. 2 vertex must not be in cycle, or
        // If childs & par are having different cycle

    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> s = obj.articulationPoints(V, adj);
		for(auto i: s)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends