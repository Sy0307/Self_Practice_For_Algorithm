#include <bits/stdc++.h>
#define NO "shuanQ"
using namespace std;
using ll = long long;
const ll maxn = 4 * 1000000000000ll;
unordered_map<ll, bool> vis;
void pre()
{
    vis[0] = vis[1] = 0;
    for (ll i = 2; i < maxn; i++)
    {
        if (!vis[i])
        {
            cout << i << endl;
            for (ll j = i * i; j < maxn; j += i)
            {
                vis[j] = 1;
                cout << j << endl;
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < maxn; i++)
    {
        if (!vis[i])
        {
            ans++;
            cout << ans << endl;
        }
    }
    cout << ans << endl;
}
void solve()
{
    // int p,q,endata;
    // cin>>p>>q>>endata;
    // for(int i=2;i<=sqrt(p*q-1);i++)
    // {
    //     if(!vis[i])
    //     {

    //     }
    // }
}

int main()
{
    ios::sync_with_stdio(false);
    pre();
    solve();
}