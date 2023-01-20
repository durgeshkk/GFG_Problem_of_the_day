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
    map<ll,set<ll>> mp;
    void bana(int n,int m,vector<vector<int>> graph){
        for(ll i = 1;i<=n;++i){
            mp[i] = {0};
        }

        for(ll i = 0;i<m;++i){
            mp[graph[i][0]].insert(graph[i][1]);
            mp[graph[i][1]].insert(graph[i][0]);
        }
    }

    bool dfs(vector<int> v,ll n){
        ll f = 1;
        for(ll i = 0;i<n-1;++i){
            set<ll> s = mp[v[i]];
            if(s.find(v[i+1]) != s.end()){

            }else{
                f = 0;
                break;
            }
        }
        if(f & 1){return true;}
        else{return false;}
    }

    long long int luckyPermutations(int N, int M, vector<int> arr,
                                    vector<vector<int>> graph) {
        // Code here
        bana(N,M,graph);
        vector<int> prev(arr);
        ll ans = 0,f = 0;
        while(prev != arr || f != 1){
            if(prev == arr){f = 1;}
            bool b = dfs(prev,prev.size());
            if(b & 1){++ans;}
            next_permutation(prev.begin(),prev.end());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<int> arr(N);
        vector<vector<int>> graph(M, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> graph[i][j];
            }
        }
        Solution obj;
        cout << obj.luckyPermutations(N, M, arr, graph) << endl;
    }
}

// } Driver Code Ends
