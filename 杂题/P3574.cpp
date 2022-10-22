#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 5e5 + 10;
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

#define int long long
void dfs(int, int);
int n;
int a[maxn], son[maxn];
int f[maxn], g[maxn];
vector<int> edge[maxn];
void solve()
{
    cin >> n;
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    fr(i, 1, n-1)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1, 0);
    cout << max(f[1], g[1] + a[1]) << endl;
}
void dfs(int u, int fa)
{
    if (u != 1)
    {
        f[u] = a[u];
    }
    for (auto &now : edge[u])
    {
        if (now == fa)
        {
            continue;
        }
        dfs(now, u);
    }
    int cnt = 0;
    for (auto &now : edge[u])
    {
        if (now == fa)
        {
            continue;
        }
        son[++cnt] = now;
    }
    sort(son + 1, son + cnt + 1, [](int a, int b)
         { return f[a] - g[a] > f[b] - g[b]; });
    fr(i, 1, cnt)
    {
        f[u] = max(f[u], f[son[i]] + g[u] + 1), g[u] += g[son[i]] + 2;
    }
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