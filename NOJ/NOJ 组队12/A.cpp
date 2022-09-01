#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 998244353;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

ll dp[maxn], a[maxn];
ll n,m,x,ans;
ll l[maxn];
void solve()
{
    int n;
    cin>>n;
    fr(i,1,n)
    {
        a[i] = 0;
        cin>>m;
        fr(j,1,m)
        {
            cin>>x;
            a[i]^=x;
        }
    }
    fr(i,1,1024)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
    fr(i,1,n)
    {
        fr(j,0,1023)
        {
            l[j] = dp[j];
        }
        fr(j,0,1023)
        {
            dp[j] = (dp[j]+l[j^a[i]])%mod;
        }
    }
    ans = 0;
    fr(i,1,1023)
    {
        ans = (ans+dp[i])%mod;
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}