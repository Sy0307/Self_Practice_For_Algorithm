#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define inl inline
#define endl '\n'
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
istream &operator>>(istream &in, vector<int> &v)
{
    for (auto &i : v)
        in >> i;
    return in;
}
ostream &operator<<(ostream &out, vector<int> &v)
{
    for (auto &i : v)
        out << i << " ";
    return out;
}
#define int ll
void solve()
{
    int n;
    cin >> n;
    vector<int> w(n + 1);
    fr(i, 1, n)
    {
        cin >> w[i];
    }
    vector<pii> g[n + 1];
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    fr(i, 1, n - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    ll ans = 0;
    function<void(int, int)> dfs = [&](int u, int fa)
    {
        dp[u][0] = 0, dp[u][1] = w[u];
        int t1 = 0, t2 = 0;
        for (auto it : g[u])
        {
            int v = it.first;
            int cost = it.second;
            if (v == fa)
                continue;
            dfs(v, u);

            if (dp[v][1] > cost)
            {
                if (dp[v][1] - cost > t1)
                {
                    t2 = t1;
                    t1 = dp[v][1] - cost;
                }
                else if (dp[v][1] - cost > t2)
                {
                    t2 = dp[v][1] - cost;
                }
            }

            dp[u][0] = max(dp[u][0], dp[v][1] + t1 + t2);
        }
        ans = max(ans, t1 + t2 + dp[u][1]);
        dp[u][1] += t1;
        return;
    };
    dfs(1, -1);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}