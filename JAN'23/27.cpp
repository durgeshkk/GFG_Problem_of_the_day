//{ Driver ele Starts
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll mod = (ll)(1e9+7);
// } Driver ele Ends
class Solution {
	public:
        // Recursion :
        /*
        map<string,ll> mp;
        set<string> ms;
        set<string> ak;
        ll ans = 0;

        void recur(ll idx,ll n,string &s,string tmp,string res){
            if(idx == n){
                // Compute & return
                if(ms.find(tmp) != ms.end()){
                    ++ans;
                    ans %= mod;
                }
                return;
            }

            tmp += s[idx];
            if(ms.find(tmp) != ms.end()){
                recur(idx+1,n,s,tmp,res);
            }

            tmp.pop_back();
            if(tmp == "0"){
                return;
            }

            if(!tmp.empty()){
                res += tmp;
                res += ',';
            }

            tmp.clear();tmp += s[idx];
            // Compute tmp
            recur(idx+1,n,s,tmp,res);
            return;
        }
        */

        // Memoization :
        vector<vector<ll>> dp;
        ll memo(string s,ll n,ll idx,ll ele){
            if(ele == 0 || ele > 26){
                return 0;
            }

            if(idx >= n) {
                return 1;
            }

            if(dp[idx][ele+1]!=-1) {
                return dp[idx][ele+1];
            }

            ll smallAns=0;
            smallAns += memo(s,n,idx+1,(s[idx]-'0'));
            smallAns %= mod;

            if(idx != 0){
                smallAns += memo(s,n,idx+1,(10*ele)+(s[idx]-'0'));
            }
            smallAns %= mod;
            
            return dp[idx][ele+1] = smallAns;
        }

		int CountWays(string str){
		    // ele here
            /*
            for(ll i = 0;i<26;++i){
                string st;
                st += ('a'+i);mp[st] = (i+1);
                st.clear();
                st = to_string(i+1);ms.insert(st);
            }
            // dp.assign(str.size()+1,-1);
            recur(0,str.size(),str,"","");
            // ans = ak.size();
            return ans/2;
            */
            
            dp.assign(str.size(),vector<ll>(28,-1));
		    return memo(str,str.size(),0,-1);
		}

};



//{ Driver ele Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver ele Ends
