#include <bits/stdc++.h>
using namespace std;
const int MAXN  = 2e5+10;
vector<int> g[MAXN];
struct edge
{
    int type, u, v;
} ed[MAXN];
int n, m;
bool vis[MAXN];
int col[MAXN], flag = 1;
int in[MAXN], topo[MAXN];
void dfs(int u, int t)
{
    if (vis[u])
    {
        if (col[u] != t)
            flag = 0;
        return;
    }
    vis[u] = 1;
    col[u] = t;
    for (int v : g[u])
    {
        dfs(v, t ^ 1);
    }
}
bool isconnect()
{
    for (int u = 1; u <= n; u++)
    {
        if (!vis[u])
            dfs(u, 0);
    }
    return flag;
}
bool istopo()
{ //拓扑排序
    for (int u = 1; u <= n; u++)
        for (int v : g[u])
            in[v]++;
    queue<int> que;
    for (int u = 1; u <= n; u++)
        if (in[u] == 0)
            que.push(u);
    int cnt = 0;
    while (que.size())
    {
        int u = que.front();
        que.pop();
        topo[u] = ++cnt;
        for (int v : g[u])
        {
            in[v]--;
            if (in[v] == 0)
                que.push(v);
        }
    }
    return cnt == n;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> ed[i].type >> ed[i].u >> ed[i].v;
        g[ed[i].u].push_back(ed[i].v);
        g[ed[i].v].push_back(ed[i].u);
    }
    if (!isconnect())
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
    }
    for (int i = 1; i <= m; i++)
    {
        int u = ed[i].u, v = ed[i].v, type = ed[i].type;
        if (col[u] == 1)
            swap(u, v);
        if (type == 1)
            g[u].push_back(v);
        else
            g[v].push_back(u);
    }

    if (!istopo())
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << (col[i] == 0 ? "L " : "R ") << topo[i] << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    solve();
}