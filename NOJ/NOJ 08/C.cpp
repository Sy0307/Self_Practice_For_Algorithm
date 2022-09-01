#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

void solve()
{
    ll n;
    cin>>n;
    ll a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll pre[n+1][n+1];
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            pre[i][j]+=pre[i-1][j];
        }
        for(int j=a[i];j<=n;j++)
        {
            pre[i][j]++;
        }
    }


    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            ans+= (pre[i-1][a[j] - 1])*(pre[n][a[i] - 1] - pre[j][a[i] - 1]);
        }
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}