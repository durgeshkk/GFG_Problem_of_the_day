//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define ll int
class Solution {
  public:
    bool canPair(vector<int> v, int k) {
        // Code here.
        for(ll i = 0;i<v.size();++i){
            v[i] %= k;
        }

        sort(v.begin(),v.end());
        ll i = 0,j = v.size()-1;
        while(v[i] == 0){
            ++i;
        }

        ll n = v.size();
        if(n & 1){return false;}
        if(i == n){return true;}
        while(i < j){
            if(v[i]+v[j] == k){
                ++i,--j;
            }else{
                return false;
            }
        }

        if(i == j){
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends