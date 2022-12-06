//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    // your code here
	    string ans;
	    reverse(a.begin(),a.end());
	    reverse(b.begin(),b.end());
	    
	    int i = 0,j = 0;
	    int carry = 0;
	    while(i != a.size() and j!=b.size()){
	        int x = a[i]-'0';int y = b[j]-'0';
	        int z = x^y^carry;
	        ans += (z+'0');
	        if((x&y==1) || (carry&y==1) || (x&carry==1)){
	            carry = 1;
	        }else{
	            carry = 0;
	        }
	        ++i,++j;
	    }
	    
	    while(i != a.size()){
	        int x = a[i]-'0';
	        int z = x^carry;
	        ans += (z+'0');
	        if((x&carry==1)){
	            carry = 1;
	        }else{
	            carry = 0;
	        }
	        ++i;
	    }
	    
	    while(j != b.size()){
	        int y = b[j]-'0';
	        int z = y^carry;
	        ans += (z+'0');
	        if((y&carry==1)){
	            carry = 1;
	        }else{
	            carry = 0;
	        }
	        ++j;
	    }
	    
	    if(carry&1){
	        ans += ('1');
	    }
	    
	   // cout<<ans<<endl;
	    i = ans.size()-1;
	    if(ans[i] == '0'){
	        while(ans[i] == '0'){
	            --i;
	        }
	        ans = ans.substr(0,i+1);
	    }

	    reverse(ans.begin(),ans.end());return ans;
	   // Check if after all carry is set then need to add extra bit
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends