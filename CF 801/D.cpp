#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, dp[maxn], kk[maxn], tot, head[maxn], du[maxn];
struct edge
{
    int to, nxt;
} E[maxn * 2];
void add(int u, int v)
{
    E[++tot] = (edge){v, head[u]};
    head[u] = tot;
}
void dfs(int now, int last)
{
    int y;
    for (int i = head[now]; i; i = E[i].nxt)
    {
        y = E[i].to;
        if (y == last)
            continue;
        dfs(y, now);
        dp[now] += dp[y];
    }
    dp[now] += max(kk[now] - 1, 0);
    if (!dp[now])
        kk[last]++;
}
void solve()
{
    int u, v;
    cin >> n;
    tot = 0;
    for (int i = 1; i <= n; i++)
        du[i] = head[i] = kk[i] = dp[i] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        add(u, v), add(v, u);
        du[u]++, du[v]++;
    }
    if (n == 1)
    {
        cout<<0<<endl;
        return;
    }
    int mx = max_element(du + 1, du + n + 1) - du;
    if (du[mx] > 2)
        dfs(mx, 0), cout << dp[mx] << endl;
    else
        cout << 1 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}