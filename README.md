# GFG_Problem_of_the_day

### head3
```c
#include <bits/stdc++.h>
#include <iomanip>
#define ll long long int
using namespace std;
ll mod = (ll)(1e9 + 7);
void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int f1 = 1;
    int f2 = 1;

    ll ans1 = 0, ans2 = 0;

    for (ll i = 0; i < 3; i++)
    {
        ll c2 = 0;
        ll p = k;
        ll c = 0;
        ll r = 0;
        ll t = 0;
        for (ll j = 0; j < n; j++)
        {
            if (p > v[j])
            {
                p += v[j] / 2;
                t++;
            }
            else
            {
                if (c == i && r == 0)
                {
                    p *= 3;
                    r = 1;
                }
                else if (c2 < 2)
                {
                    p *= 2;
                    c2++;
                }
                else
                {
                    break;
                }
                j--;
                c++;
            }
        }
        ans1 = max(ans1, t);
    }

    cout << max(ans1, ans2) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();
    return 0;
}
  ```
