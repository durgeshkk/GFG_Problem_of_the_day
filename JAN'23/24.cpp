//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
#define ll int
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    // code here
        multiset<pair<ll,ll>> ms;
        for(ll i= 0;i<n;++i){
            ms.insert({arr[i],i});
        }

        ll cnt = 0;
        while(!ms.empty()){
            auto p = *ms.begin();
            ms.erase(ms.find(p));
            arr[p.second] = cnt;
            ++cnt;
        }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends