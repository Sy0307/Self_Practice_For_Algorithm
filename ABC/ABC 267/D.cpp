#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2010;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

ll dp[maxn][maxn];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    memset(dp, -0x3f, sizeof(dp));
    fr(i, 0, n)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m && j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i] * j);
        }
    }
    cout << dp[n][m] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}