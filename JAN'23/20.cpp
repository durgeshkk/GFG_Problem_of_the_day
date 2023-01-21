//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define ll int
class Solution
{
  public:
    int maxWeightCell(int n, vector<int> v){
        ll ans = 0;
        vector<ll> store(n+1,0);
        for(ll i = 0;i<n;++i){
            if(v[i] == -1){continue;}
            store[v[i]] += i;
        }

        ll mx = 0;
        for(ll i = 0;i<n;++i){
            if(store[i] >= mx){
                mx = store[i];
                ans = i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends