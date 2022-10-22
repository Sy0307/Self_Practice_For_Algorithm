#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 5010 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

ll a[maxn];
ll dp[maxn][maxn];
ll b[maxn];
void solve()
{
    int n,m;
    cin>>n>>m;
    fr(i,1,n)
    {
        cin>>a[i];
    }
    fr(i,1,m)
    {
        int x,y;
        cin>>x>>y;
        b[x] = y;
    }
    fr(i,1,n)
    {
        fr(j,1,i)
        {
            dp[i][j] = dp[i - 1][j - 1] +a[i]+b[j];
        }
        dp[i][0] = 0;
        fr(j,0,i)
        {
            dp[i][0] = max(dp[i][0] , dp[i-1][j]);
        }
    }
    ll ans = 0;
    fr(i,0,n)
    {
        ans = max(ans,dp[n][i]);
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}