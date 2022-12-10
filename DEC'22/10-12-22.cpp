//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
#define ll int

// Will give 100% wrong results as tmp is also changing everytime , so we need 3D
// dp & it's nt pssbl to get idx of a string tmp like, dp[i][cnt][tmp] this is very
// wrong as tmp is a string & idx of string is nvr pssbl , solution to it is use of
// map, everytime in map insert the string & check what's it's idx!!
// Make dp like dp[i][cnt][mp[tmp]]
string recur(string &s,ll i,ll n,ll cnt, ll k,vector<vector<string>> &dp,string tmp,string &st){
    // cout<<i<<" ";
    if((i == n)){
        cout<<i<<" ->"<<cnt<<" ->"<<tmp<<endl;
        return tmp;
    }

    // cout<<i<<" "<<cnt<<" "<<tmp<<endl;
    
    if(dp[i][cnt] != st){
        return dp[i][cnt];
    }

    if(cnt == k){
        // Go with keeping all
        tmp += s[i];
        cout<<i<<" <- "<<cnt<<" <- "<<tmp<<endl;
        return dp[i][cnt] = min(dp[i][cnt],(recur(s,i+1,n,cnt,k,dp,tmp,st)));
    }else{
        // Increment cnt/ keep the char
        // Keep min. of them
        // string ak = tmp;
        // tmp += s[i];
        return dp[i][cnt] = min(dp[i][cnt],min(recur(s,i+1,n,cnt,k,dp,tmp+s[i],st),recur(s,i+1,n,cnt+1,k,dp,tmp,st)));
    }
}

string buildLowestNumber(string s, int k)
{
    //code here.
    string st;
    stack<ll> dynamo;

    for(ll i = 0;i<s.size();++i){
        if(dynamo.empty()){dynamo.push(s[i]-'0');}
        else if(dynamo.top() <= (s[i]-'0')){dynamo.push(s[i]-'0');}
        else if(k == 0){dynamo.push(s[i]-'0');}
        else{
            ll ch = (s[i]-'0');
            while(!dynamo.empty() and dynamo.top() > ch){
                dynamo.pop();
                --k;
                if(k == 0){break;}
            }
            dynamo.push(ch);
        }
        // cout<<dynamo.size()<<endl;
    }

    while(k > 0){
        dynamo.pop();--k;
    }

    while(!dynamo.empty()){
        st.push_back((dynamo.top()+'0'));
        dynamo.pop();
    }
    
    // cout<<st<<endl;
    while(st.size() > 0 and st[st.size()-1] == '0'){
        st.pop_back();
    }

    if(st.size() == 0){
        st += '0';
    }
    
    reverse(st.begin(),st.end());

    /*
    string st = "";
    string tmp = "";
    vector<vector<string>> dp(s.size()+1,vector<string>(k+1,"-1"));

    for(ll i = 0;i<=s.size();++i){
        st += '9';
    }

    for(ll i = 0;i<=s.size();++i){
        for(ll j = 0;j<=k;++j){
            dp[i][j] = st;
        }
    }

    st = recur(s,0,s.size(),0,k,dp,tmp,st);

    cout<<dp.size()<<" "<<dp[0].size()<<endl;
    for(ll i = 0;i<=s.size();++i){
        for(ll j = 0;j<=k;++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    */
    return st;
}