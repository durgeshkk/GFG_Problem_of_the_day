//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


#define ll int
class Solution
{
public:
    string longestString(vector<string> &v)
    {
        // code here
        sort(v.begin(), v.end());
        unordered_map<string,bool> mp;
        
        ll n = v.size();
        for(ll i=0;i<n;++i){
            if(v[i].size() != 1){
                string temp = v[i];
                temp.pop_back();
                if(!mp[temp]){
                    mp[v[i]] = false;
                }else{
                    mp[v[i]] = true;
                }
            }else{
                mp[v[i]] = true;
            }
        }

        string ans = "";
        for(ll i=0;i<n;++i){
            if(mp[v[i]] && (v[i].size() > ans.size())){
                ans = v[i];
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends