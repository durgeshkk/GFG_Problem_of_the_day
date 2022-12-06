//{ Driver Code Starts
// Initial Template for C++

// Initial Template for C++
// Back-end complete function Template for C++
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define ll long long int
class Solution {
  public:
    long long lcmTriplets(long long n) {
        // code here
        if(n <= 2){
            return n;
        }
        
        if(n%6 == 0){
            ll ans = (n-1)*(n-2)*(n-3);
            ll mx = n*(n-1)*(n-5);
            return max(mx,ans);
        }
        
        ll a = n,b = n-1;
        if(a%2){
            // a is odd b is even & now apply BS for c
            return (a*b*(n-2));
        }else{
            // a is even b is odd & now apply BS for c
            return max(a*b*(n-2)/2,a*b*(n-3));
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    }
}
// } Driver Code Ends