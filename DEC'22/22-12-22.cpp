//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
#define ll long long int
class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &v, int n ) {
        //code here
        map<ll,ll> mp;
        ll sm = 0,ans = 0;

        for(ll i = 0;i<n;++i){
            sm += v[i];
            mp[sm]++;
        }

        for(auto it:mp){
            if(it.first == 0){
                ans += (it.second*(it.second+1)/2);
            }else{
                ans += (it.second*(it.second-1)/2);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends