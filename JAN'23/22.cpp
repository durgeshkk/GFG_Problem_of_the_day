//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


#define ll int
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
// } Driver Code Ends
class Solution {
  public:
    vector<ll> factors;
    void printDivisors(ll n)
    {
        // Note that this loop runs till square root
        for (ll i=1; i<=sqrt(n); i++){
            if (n%i == 0){
                if (n/i == i){
                    factors.push_back(i);
                }else{
                    factors.push_back(i);
                    factors.push_back(n/i);
                }
            }
        }
    }

    int solve(int n, int k, vector<int> &v) {
        ll sum = accumulate(v.begin(),v.end(),0ll);
        printDivisors(sum);
        ll ans = 0;
        for(auto x:factors){
            // "x" is a gcd
            ll cnt = 0,sm = 0;
            for(ll i = 0;i<n;++i){
                sm += v[i];
                if(sm%x == 0){
                    ++cnt;
                    sm = 0;
                }
            }

            if(cnt < k){
                continue;
            }else{
                ans = max(ans,x);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
