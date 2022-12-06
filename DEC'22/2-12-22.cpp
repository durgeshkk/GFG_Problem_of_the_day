//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string s, string t, int m, int n) {
        // code here
        int ans = 1;
        int i = 0,j = 0,idx = -1,req = -1;

        if(m != n){return 0;}

    // Check for A :
        int f = 0;
        while(i<m){
            if(t[j] == 'A'){
                req = j;
            }else{
                while(t[j] != 'A' and j<n){
                    ++j;
                }
                if(j < n){
                    req = j;
                }
            }

            if(j == n){break;}

            if(f == 0){
                i = j;
            }

            if(s[i] == 'A'){
                swap(s[i],s[j]);++j;f = 0;
            }else if(s[i] == 'B'){
                return 0;
            }else{
                ++i;f = 1;
            }

        }

    // Check for B :
        i = m-1,j=n-1;
        f = 0;
        while(i>=0){
            if(t[j] == 'B'){
            }else{
                while(t[j] != 'B' and j> -1){
                    --j;
                }
                if(j == -1){break;}
            }

            if(f == 0){
                i = j;
            }

            if(s[i] == 'B'){
                swap(s[i],s[j]);--j;f = 0;
            }else if(s[i] == 'A'){
                return 0;
            }else{
                --i;f = 1;
            }
        }

        if(s == t){return 1;}
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends