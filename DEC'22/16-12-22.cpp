//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define ll int
class Solution{
public:

    bool check(vector<vector<int>> v,ll i,ll j){
        ll n = v.size(),m = v[0].size();
        if(i < 0 || j < 0 || i>=n || j>=m){
            return false;
        }
        return true;
    }

    int hopscotch(int n, int m, vector<vector<int>> v, int ty, int i, int j)
    {
        // code here
        // Row koi bhi ho locha col create kr rha !!
        // If col is odd it's close to below diagonals!!
        ll ans = 0;

        if(j%2 == 0 && ty == 0) {
            if(check(v,i-1, j)) ans += v[i-1][j];
            if(check(v,i, j+1)) ans += v[i][j+1];
            if(check(v,i-1, j-1)) ans += v[i-1][j-1];
            if(check(v,i+1, j)) ans += v[i+1][j];
            if(check(v,i, j-1)) ans += v[i][j-1];
            if(check(v,i-1, j+1)) ans += v[i-1][j+1];
            return ans;
        }
        
        if(j%2 == 1 && ty == 0) {
            if(check(v,i-1, j)) ans += v[i-1][j];
            if(check(v,i, j-1)) ans += v[i][j-1];
            if(check(v,i+1, j+1)) ans += v[i+1][j+1];
            if(check(v,i+1, j)) ans += v[i+1][j];
            if(check(v,i+1, j-1)) ans += v[i+1][j-1];
            if(check(v,i, j+1)) ans += v[i][j+1];
            
            return ans;
        }
        
        
        if(j%2 == 0 && ty == 1) {
            if(check(v,i-2, j)) ans += v[i-2][j];
            if(check(v,i-2, j+1)) ans += v[i-2][j+1];
            if(check(v,i, j+2)) ans += v[i][j+2];
            if(check(v,i, j-2)) ans += v[i][j-2];
            if(check(v,i+1, j+1)) ans += v[i+1][j+1];
            if(check(v,i-1, j+2)) ans += v[i-1][j+2];
            if(check(v,i+2, j)) ans += v[i+2][j];
            if(check(v,i+1, j+2)) ans += v[i+1][j+2];
            if(check(v,i+1, j-1)) ans += v[i+1][j-1];
            if(check(v,i+1, j-2)) ans += v[i+1][j-2];
            if(check(v,i-1, j-2)) ans += v[i-1][j-2];
            if(check(v,i-2, j-1)) ans += v[i-2][j-1];
            return ans;
        }
        
        
        if(j%2 == 1 && ty == 1) {
            if(check(v,i-2, j)) ans += v[i-2][j];
            if(check(v,i+1, j+2)) ans += v[i+1][j+2];
            if(check(v,i-1, j+2)) ans += v[i-1][j+2];
            if(check(v,i, j+2)) ans += v[i][j+2];
            if(check(v,i+2, j+1)) ans += v[i+2][j+1];
            if(check(v,i-1, j+1)) ans += v[i-1][j+1];
            if(check(v,i+2, j)) ans += v[i+2][j];
            if(check(v,i+1, j-2)) ans += v[i+1][j-2];
            if(check(v,i-1, j-2)) ans += v[i-1][j-2];
            if(check(v,i, j-2)) ans += v[i][j-2];
            if(check(v,i+2, j-1)) ans += v[i+2][j-1];
            if(check(v,i-1, j-1)) ans += v[i-1][j-1];
            
            return ans;
        }
        
        /*
        if(j & 1){
            if(ty == 0){
                // Collect stone at dist 1
                if(check(i-1,j,n,m)){
                    ans += (v[i-1][j]);
                }
                if(check(i,j+1,n,m)){
                    ans += (v[i][j+1]);
                }
                if(check(i+1,j+1,n,m)){
                    ans += (v[i+1][j+1]);
                }
                if(check(i+1,j,n,m)){
                    ans += (v[i+1][j]);
                }
                if(check(i+1,j-1,n,m)){
                    ans += (v[i+1][j-1]);
                }
                if(check(i,j-1,n,m)){
                    ans += (v[i][j-1]);
                }
            }else{
                // Collect stone at dist 2
                if(check(i,j-2,n,m)){
                    ans += v[i][j-2];
                }
                if(check(i+1,j-2,n,m)){
                    ans += v[i+1][j-2];
                }
                if(check(i,j+2,n,m)){
                    ans += v[i][j+2];
                }
                if(check(i+1,j+2,n,m)){
                    ans += v[i+1][j+2];
                }
                if(check(i-1,j-1,n,m)){
                    ans += v[i-1][j-1];
                }

                if(check(i+2,j-1,n,m)){
                    ans += v[i+2][j-1];
                }

                if(check(i+2,j+1,n,m)){
                    ans += v[i+2][j+1];
                }

                if(check(i-1,j+1,n,m)){
                    ans += v[i-1][j+1];
                }

                if(check(i-2,j,n,m)){
                    ans += v[i-2][j];
                }
                
                if(check(i+2,j,n,m)){
                    ans += v[i+2][j];
                }
            }
        }else{
            if(ty == 0){
                if(check(i-1,j,n,m)){
                    ans += (v[i-1][j]);
                }
                if(check(i-1,j+1,n,m)){
                    ans += (v[i-1][j+1]);
                }
                if(check(i,j+1,n,m)){
                    ans += (v[i][j+1]);
                }
                if(check(i+1,j,n,m)){
                    ans += (v[i+1][j]);
                }
                if(check(i,j-1,n,m)){
                    ans += (v[i][j-1]);
                }
                if(check(i-1,j-1,n,m)){
                    ans += (v[i-1][j-1]);
                }
            }else{
                if(check(i,j-2,n,m)){
                    ans += v[i][j-2];
                }
                if(check(i+1,j-1,n,m)){
                    ans += v[i+1][j-1];
                }
                if(check(i+1,j+1,n,m)){
                    ans += v[i+1][j+1];
                }
                if(check(i,j+2,n,m)){
                    ans += v[i][j+2];
                }
                if(check(i-1,j+2,n,m)){
                    ans += v[i-1][j+2];
                }
                if(check(i-1,j-2,n,m)){
                    ans += v[i-1][j-2];
                }
                if(check(i-2,j-1,n,m)){
                    ans += v[i-2][j-1];
                }
                if(check(i-2,j+1,n,m)){
                    ans += v[i-2][j+1];
                }
                if(check(i-2,j,n,m)){
                    ans += v[i-2][j];
                }
                if(check(i+2,j,n,m)){
                    ans += v[i+2][j];
                }
            }
        }*/
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends