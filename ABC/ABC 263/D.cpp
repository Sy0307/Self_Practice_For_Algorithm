#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

int a[maxn];
ll dp[3][maxn];
void solve()
{
    ll n,l,r;
    cin>>n>>l>>r;
    fr(i,1,n)
    {
        cin>>a[i];
    }
    dp[0][0] = dp[1][0] = dp[2][0] = 0;
    fr(i,1,n)
    {
        dp[0][i] = dp[0][i-1] + l;
        dp[1][i] = min(dp[0][i],dp[1][i-1]+a[i]);
        dp[2][i] = min(dp[2][i-1]+r,dp[1][i]);
    }
    cout<<dp[2][n]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}