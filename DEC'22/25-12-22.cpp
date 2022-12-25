//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long int
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& mat) {
        // Code here
        int n = mat.size();
        ll sm = 0,prev = -1;
        int row = -1,col = -1;

        for(int i=0;i<n;++i){
            int f = 0;ll row_sm = 0;
            for(int j=0;j<n;++j){
                if(mat[i][j] != 0){
                    row_sm += mat[i][j];
                }else{
                    row = i;
                    col = j;
                    f = 1;
                }
            }
            if(f == 0){
                if(prev == -1){
                    prev = row_sm;
                }else if(prev != row_sm){
                    return -1;
                }
            }else{
                sm = row_sm;
            }
        }

        ll ans = (prev-sm);
        prev = -1;
        for(int j=0;j<n;++j){
            ll col_sm = 0;
            for(int i=0;i<n;++i){
                if(i == row && j == col){
                    col_sm += ans;
                }else{
                    col_sm += mat[i][j];
                }
            }
            if(prev != -1){
                if(col_sm != prev){
                    return -1;
                }
            }else{
                prev = col_sm;
            }
        }

        ll sm1 = 0;
        for(ll i=0;i<n;++i){
            if(i==col && i==row){
                sm1 += ans;
            }else{
                sm1 += mat[i][i];
            }
        }

        ll sm2 = 0;
        for(ll i=0;i<n;++i){
            if(n-i-1==col && i==row){
                sm2 += ans;
            }else{
                sm2 += mat[i][n-i-1];
            }
        }
        if(sm1 != sm2 || ans <= 0)
            return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends