#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;

vector<int> edge[maxn];
int x[maxn], y[maxn], dis[maxn];
int n, m;

int bfs(int x) //求树的直径
{
    memset(dis, 0, sizeof(dis));
    queue<int> q;
    q.push(x);
    dis[x] = 1;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < edge[now].size(); i++)
        {
            if (dis[edge[now][i]] == 0)
            {
                dis[edge[now][i]] = dis[now] + 1;
                q.push(edge[now][i]);
            }
        }
    }
    int ma = 0;
    for (int i = 1; i <= n; i++)
        if (ma < dis[i])
        {
            ma = dis[i];
            x = i;
        }
    memset(dis, 0, sizeof(dis));
    q.push(x);
    dis[x] = 1;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < edge[now].size(); i++)
        {
            if (dis[edge[now][i]] == 0)
            {
                dis[edge[now][i]] = dis[now] + 1;
                q.push(edge[now][i]);
            }
        }
    }
    ma = 0;
    for (int i = 1; i <= n; i++)
        if (ma < dis[i])
        {
            ma = dis[i];
        }
    return ma - 1;
}

int f(int k) //舍弃第k条边
{
    for (int i = 1; i <= n; i++)
        edge[i].clear();
    for (int i = 1; i < n; i++)
    {
        if (i != k)
        {
            edge[x[i]].push_back(y[i]);
            edge[y[i]].push_back(x[i]);
        }
    }
    return bfs(x[k]) * bfs(y[k]);
}
void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, f(i));
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    solve();
}