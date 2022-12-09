//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends

#define ll long long int
ll mod = (ll)(1e9+7);
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m)
{
    // write code here
    ll a = n*m;
    ll b = n*m-1;
    a %= mod;
    b %= mod;

    ll ans = mod_mul(a,b,mod);
    // More the mod more the time it consumes!!
    // Better use a variable & then later use mod
    // at last...
    ll val = 0;
    
    for(ll i=0;i<n;++i){
        for(ll j= 0;j<m;++j){
            if(j-2 >= 0){
                if(i-1 >= 0){
                    ++val;
                    // ans = mod_sub(ans,1,mod);
                }
                if(i+1 < n){
                    ++val;
                    // ans = mod_sub(ans,1,mod);
                }
            }
            if(j-1 >= 0){
                if(i-2 >= 0){
                    ++val;
                    // ans = mod_sub(ans,1,mod);
                }
                if(i+2 < n){
                    ++val;
                    // ans = mod_sub(ans,1,mod);
                }
            }
            if(j+2 < m){
                if(i-1 >= 0){
                    ++val;
                    // ans = mod_sub(ans,1,mod);
                }
                if(i+1 < n){
                    ++val;
                    // ans = mod_sub(ans,1,mod);
                }
            }
            if(j+1 < m){
                if(i-2 >= 0){
                    ++val;
                    // ans = mod_sub(ans,1,mod);
                }
                if(i+2 < n){
                    ++val;
                    // ans = mod_sub(ans,1,mod);
                }
            }
        }
    }
    
    val %= mod;
    ans = mod_sub(ans,val,mod);
    return ans;
}
