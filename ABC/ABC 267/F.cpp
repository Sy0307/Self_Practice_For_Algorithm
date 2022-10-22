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

const int N = 2e5 + 5;
int n, dep[maxn], fa[maxn][21];
vector<int> g[maxn];
void dfs_lca(int u, int father)
{
    dep[u] = dep[father] + 1;
    fa[u][0] = father;
    for (int i = 1; (1 << i) <= dep[u]; i++)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto child : g[u])
    {
        if (child != father)
        {
            dfs_lca(child, u);
        }
    }
}
int lca(int a, int b)
{
    if (dep[a] > dep[b])
    {
        swap(a, b);
    }
    for (int i = 20; i >= 0; i--)
    {
        if (dep[a] <= dep[b] - (1 << i))
        {
            b = fa[b][i];
        }
    }
    if (a == b)
    {
        return a;
    }
    for (int i = 20; i >= 0; i--)
    {
        if (fa[a][i] == fa[b][i])
            continue;
        else
        {
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}
int find(int u, int k)
{
    int depth = dep[u] - k;
    for (int i = 20; i >= 0; i--)
    {
        if (dep[u] >= depth + (1 << i))
        {
            u = fa[u][i];
        }
    }
    return u;
}
int dis(int a, int b)
{
    return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}
void solve()
{
    cin >> n;
    fr(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs_lca(1, 0);
    int L = 1, R = 1;
    fr(i, 1, n)
    {
        if (dis(1, i) > dis(1, L))
        {
            L = i;
        }
    }
    fr(i, 1, n)
    {
        if (dis(L, i) > dis(L, R))
        {
            R = i;
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int u, k;
        cin >> u >> k;
        if (k > dis(u, L) && k > dis(u, R))
        {
            cout << -1 << endl;
            continue;
        }
        if (dis(L, u) > dis(R, u))
            swap(L, R);
        if (k <= dis(u, lca(u, R)))
        {
            cout << find(u, k) << endl;
        }
        else
        {
            cout << find(R, dis(u, R) - k) << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}