//{ Driver Code Starts
#include<bits/stdc++.h>
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;

#define ll int
// } Driver Code Ends
class Solution{
    public:
    string rearrange (string s, int n)
    {
        // your code here
        vector<ll> vow(27,0);
        vector<ll> cons(27,0);
        ll cntv=0,cntc=0;


        for(ll i = 0;i<n;++i){
            if((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u')){
                vow[s[i]-'a']++;++cntv;
            }else{
                cons[s[i]-'a']++;++cntc;
            }
        }

        // show(vow);
        {
        // TLE Step:
        // sort(vow.begin(),vow.end());
        // sort(cons.begin(),cons.end());
        }

        if((cntv == cntc)){
            vector<ll> tmp1(vow),tmp2(cons);
            // check both combos
            ll f = 0,j=0,k=0;
            for(ll i = 0;i<n;++i){
                if(f == 0){
                    while((j < 26) and (vow[j] == 0)){
                        ++j;
                    }
                    s[i] = (j+'a');
                    vow[j]--;
                }else{
                    while((k < 26) and (cons[k] == 0)){
                        ++k;
                    }
                    s[i] = (k+'a');
                    cons[k]--;
                    // s[i] = cons[k];++k;
                }f ^=1;
            }

            string s2;
            f = 0,j=0,k=0;
            for(ll i = 0;i<n;++i){
                if(f == 0){
                    while((k < 26) and (tmp2[k] == 0)){
                        ++k;
                    }
                    s2 += (k+'a');
                    tmp2[k]--;
                }else{
                    while((j < 26) and (tmp1[j] == 0)){
                        ++j;
                    }
                    s2 += (j+'a');
                    tmp1[j]--;
                }f ^=1;
            }
            if(s2 < s){s = s2;}

        }else if((cntv == 1+cntc)){
            ll f = 0,j=0,k=0;
            for(ll i = 0;i<n;++i){
                if(f == 0){
                    while((j < 26) and (vow[j] == 0)){
                        ++j;
                    }
                    s[i] = (j+'a');
                    vow[j]--;
                }else{
                    while((k < 26) and (cons[k] == 0)){
                        ++k;
                    }
                    s[i] = (k+'a');
                    cons[k]--;
                }f ^= 1;
            }
        }else if(cntv+1 == cntc){
            ll f = 0,j=0,k=0;
            for(ll i = 0;i<n;++i){
                if(f == 0){
                    while((k < 26) and (cons[k] == 0)){
                        ++k;
                    }
                    s[i] = (k+'a');
                    cons[k]--;
                }else{
                    while((j < 26) and (vow[j] == 0)){
                        ++j;
                    }
                    s[i] = (j+'a');
                    vow[j]--;
                }f ^=1;
            }
        }else{
            s.clear();
            s = "-1";
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; 
        // cin >> n;
		string s; cin >> s;
        n = s.size();
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends