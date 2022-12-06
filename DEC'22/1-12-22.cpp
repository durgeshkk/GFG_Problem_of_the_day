//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
#define ll long long
class Solution{
    
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *v, int n) 
    { 
        // TC = O(N), SC = O(N)
        /*
        vector<ll> small,big;
        for(ll i = 0;i<n/2;++i){
            small.push_back(v[i]);
        }
        for(ll i = n-1;i>=n/2;--i){
            big.push_back(v[i]);
        }

        ll k = 0,j = 0,f = 0;
        for(ll i = 0;i<n;++i){
            if(f == 0){
                v[i] = big[k];
                ++k;
            }else{
                v[i] = small[j];
                ++j;
            }
            f ^= 1;
        }
        // show(big);
        // show(small);
        // for(ll i = 0;i<n;++i){
        //     cout<<v[i]<<" ";
        // }cout<<endl;

        return;*/
        
        // TC = O(N), SC = O(1) {Incomplete}
        // /*
        ll mid = n/2;
        ll i = mid-1,j = -1;
        if(n & 1){
            j = n-2;
        }else{
            j = n-1;
        }

        while(i >= 0){
            swap(v[i],v[j]);
            --i;
            j -= 2;
        }

        // for(ll i=  0;i<n;++i){
        //     cout<<v[i]<<" ";
        // }cout<<endl;
        return;
        i = 0;
        if(n & 1){
            j = n-1;
        }else{
            j = n-2;
        }

        while(j >= 0){
            if(v[i] < v[j]){
                swap(v[i],v[j]);
            }
            j -= 2;
        }
        // */
        // TLE :
        /*
    	 multiset<ll> ms;
    	 for(ll i = 0;i<n;++i){
    	     ms.insert(arr[i]);
    	 }
    	 
    	 ll f = 0;
    	 for(ll i = 0;i<n;++i){
    	     if(f == 0){
    	         ll val = *ms.rbegin();
    	         ms.erase(ms.find(val));
    	         arr[i] = val;
    	     }else{
    	         ll val = *ms.begin();
    	         ms.erase(ms.find(val));
    	         arr[i] = val;
    	     }
    	     f ^= 1;
    	 }*/
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends