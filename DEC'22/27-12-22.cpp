//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

#define ll long long
long long maxArea(long long A[], int len)
{
    // Your code goes here
    ll i=0,j=len-1;
    ll ans =0;

    while(i<j){
        ll mid = min(A[j],A[i])*(j-i);
        ans=max(ans,mid);
        if(A[i]<A[j]){
            i++;
        }else{
            --j;
        }
    }
    return ans;
}


//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends