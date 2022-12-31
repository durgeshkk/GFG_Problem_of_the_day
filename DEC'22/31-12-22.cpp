//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#define ll int
class Solution {
  public:
    int minLaptops(int n, int s[], int e[]) {
        // Code here
        ll ans = 0;
        vector<pair<ll,ll>> v;
        for(ll i = 0;i<n;++i){
            v.push_back({s[i],e[i]});
        }

        sort(v.begin(),v.end());
        priority_queue<int,vector<int>,greater<int>> pq;

        for(ll i=0;i<n;i++){
            if(pq.size()==0){ 
                ans++; 
                pq.push(v[i].second);
            }else if(pq.top()<=v[i].first){
               pq.pop();
               pq.push(v[i].second);
            }else{
                pq.push(v[i].second);
                ++ans;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends