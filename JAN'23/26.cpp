//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#define ll int
class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        string up,low;
        for(ll i = 0;i<n;++i){
            if(s[i] >= 'a' and s[i] <= 'z'){
                low += s[i];
            }else{
                // Convert up -> low and then sort & return low 
                char ch = (s[i]-'A'+'a');
                // low += (ch);
                up += s[i];
            }
        }
        
        sort(up.begin(),up.end());
        sort(low.begin(),low.end());

        ll j = 0,k = 0;
        for(ll i = 0;i<n;++i){
            if(s[i] >= 'a' and s[i] <= 'z'){
                s[i] = low[j];++j;
            }else{
                s[i] = up[k];++k;
            }
        }
        return s;

        /*
        ll j = up.size()-1;
        for(ll i = n-1;i>=0;--i){
            if(low[i]-'a'+'A' == up[j]){
                --j;
                low[i] = (low[i]-'a'+'A');
            }
        }
        string ans = low;
        // ans += up;
        return ans;
        */
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
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends