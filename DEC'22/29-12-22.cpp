//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &asteroids) {
        // code here
        stack<int> st;
        for(ll i = 0;i<n;++i){
            if(st.empty()){
                st.push(asteroids[i]);
            }else{
                ll x = asteroids[i];
                if(x>0){
                    st.push(x);
                }
                else{
                    while(!st.empty() && st.top()>0 && st.top()<abs(x)){
                        st.pop();
                    }
                    if(!st.empty() && st.top() == abs(x)){
                        st.pop();
                        continue;
                    }
                    if(!st.empty() && st.top()>abs(x)){
                        continue;
                    }
                    st.push(x);
                }
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends