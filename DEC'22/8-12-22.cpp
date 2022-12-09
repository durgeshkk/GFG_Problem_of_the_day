//{ Driver Code Starts
#include<bits/stdc++.h> 
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std; 

// } Driver Code Ends

#define ll long long int
class Solution
{
public:
    vector<ll> pr_sq;

    int createsieve(int n){
        bool sieve[n+1];
        memset(sieve,true,sizeof(sieve));
        int cnt = 0;
        int ntlen = n;
        
        sieve[0] = 0;
        sieve[1] = 0;

        for(int i = 2;i*i<=ntlen;++i){
            // Set all multiples to 0
            if(sieve[i] == true){
                // cout<<"i"<<endl;
                ++cnt;
                for(ll j = i*i;j<=ntlen;j+=i){
                     sieve[j] = false;
                }
            }
        }
        return cnt;
    }

    bool isPrime(int n){
        if(n<2 || n%2==0 || n%3==0){
            return false;
        }

        for(int i=5; i*i <= n; i+=6){
            if(n%i==0 || n%(i+2)==0){
                return false;
            }
        }
        return true;
    }

    // 3 div is only pssbl for 4 from even
    // from odd it's pssbl for all sqrt no.'s which r not the sqaures 
    // like 9,25,49,(81,nt pssbl since it's sq of 9),121,
    //      3,5,7,11,13,..i,e, prime no.'s squares only!!
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int> ans(query.size());
        // show(pr_sq);
        for(ll i = 0;i<q;++i){
            int x = sqrt(query[i]);
            int cnt = 0;

            if(x >= 2){++cnt;}
            if(x >= 3){++cnt;}

            for(ll j = 5;j<=x;j+=6){
                if(isPrime(j+2) and (j+2) <= x){
                    ++cnt;
                }

                if(isPrime(j)){++cnt;}
            }

            ans[i] = cnt;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
 