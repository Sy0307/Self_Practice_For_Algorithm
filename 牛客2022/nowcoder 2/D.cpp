#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
struct ed
{
    int v;
    double exp;
};

double dis[maxn][maxn];

vector<ed> edge[maxn];
bool vis[maxn];
void dijk(int x)
{
    using pii = pair<int, double>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({x, 1});
    memset(vis, 0, sizeof(vis));
    for(int i=1;i<=maxn;i++)
    {
        dis[x][i] = INT_MAX;
    }
    vis[x] = 1;
    while(pq.size())
    {
        auto now = pq.top();
        pq.pop();
        for(auto &q:edge[now.first])
        {
            auto &v = q.v;
            auto &exp = q.exp;
            if(!vis[v])
            {
                vis[v] = 1;
                double k = exp*now.second;
                dis[x][v] = min(dis[x][v], exp*now.second);
                pq.push({v, dis[x][v]});
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        edge[i].clear();
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        double exp = double(c) / double(a);
        edge[b].push_back({d, exp});
    }
    for(int i=1;i<=n;i++)
        dijk(i);
    double ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            else
            {
                if (dis[i][j] ==INT_MAX || dis[j][i] ==INT_MAX)
                {
                    continue;
                }
                double exp = dis[i][j] * dis[j][i];
            //    cout<<sqrt(1.000000 / exp)<<endl;
                ans = min(ans, sqrt(1.000000 / exp));
            }
        }
    }
    printf("%.10f\n", ans);
}
int main()
{
    ios::sync_with_stdio(false);
    solve();
}
