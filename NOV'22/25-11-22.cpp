//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include <bits/stdc++.h>
#define ll long long int
class Solution{
public:
    
    ll nCr(ll n, ll r){
 
        // p holds the value of n*(n-1)*(n-2)...,
        // k holds the value of r*(r-1)...
        if(r > n){return 0;}
    
        ll p = 1;
        for(ll i=0;i<r;++i){
            p *= (n-i);
            p /= (i+1);
        }
        return p;
    }
 
    
    long long count(long long x) {
        // Code Here
        
        if(x == 1){return 0;}
        
        ll n = x,idx = 0;
        ll cnt = 0,ans = 0;
        
        while(n){
            if(n & 1){
                ++cnt;
                ans += nCr(idx,cnt);
            }
            ++idx;
            n /= 2;
        }
        
        
        /*
        bitset<40> s(x);
        for(ll i = 0;i<40;++i){
            if(s[i] == 1){++cnt;idx = i;}
        }
        ++idx;
        
        ll ans = nCr(idx,cnt)-1;
        
        for(int i = idx;i>=0;--i){
            if(s[i] == 1){
                
            }
        }*/
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    
	int t;
	cin >> t;
	while (t-- > 0) {
	    long long x; cin >> x;
	    Solution ob;
	    cout << ob.count(x) << '\n';
	}
	return 0;
}
// } Driver Code Ends