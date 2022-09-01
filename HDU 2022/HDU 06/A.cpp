#include <bits/stdc++.h>
using namespace std;
#define re register
#define il inline
il int read()
{
    re int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}
struct Edge
{
    int u, v, w;
} edge[200005];
int fa[100005], n, m, ans, eu, ev, cnt;
il bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
il int find(int x)
{
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}
bool vis[200005];
il void kruskal()
{
    sort(edge, edge + m, cmp);
    for (re int i = m - 1; i >=0; i--)
    {
        eu = find(edge[i].u), ev = find(edge[i].v);
        if (eu == ev)
        {
            continue;
        }
        ans ++;
        vis[i] = 1;
        fa[ev] = eu;
        if (++cnt == n - 1)
        {
            break;
        }
    }
}
void solve()
{
    ans = 0,cnt = 0;
    n = read(), m = read();
    for (re int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (re int i = 0; i < m; i++)
    {
        vis[i] = 0;
        edge[i].u = read(), edge[i].v = read(), edge[i].w = i;
    }
    kruskal();
    // if(ans!=n-1)
    // {
    //     printf("0\n\n");
    //     return;
    // }
    printf("%d\n", m - ans);
    for (int i = 0; i < m; i++)
    {
        if (!vis[i])
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}
int main()
{
    ios::sync_with_stdio(false);
    int T = read();
    while (T--)
    {
        solve();
    }
}