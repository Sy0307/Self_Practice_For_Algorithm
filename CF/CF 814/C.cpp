#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 35;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

vector<int> g[maxn];
int gg[maxn][maxn];
ll cnt[15][maxn];
int vis[15][maxn];
int n, k;
struct node
{
    ll step, pos;
};
void pre()
{
    cin >> n >> k;
    int x, y;
    while (cin>>x && x != -1)
    {
        cin >> y;
        if (!gg[x][y])
        {
            g[x].push_back(y);
            ++gg[x][y];
        }
    }
}
void bfs(int s)
{
    queue<node> q;
    q.push({0, s});
    cnt[0][s] = 1;
    vis[0][s] = 1;
    while (q.size())
    {
        auto now = q.front();
        int u = now.pos;
        if (now.step > k)
            return;
        q.pop();
        for (auto &v : g[u])
        {
            cnt[now.step + 1][v] += cnt[now.step][u];
            if (!vis[now.step + 1][v])
            {
                q.push({now.step + 1, v});
                vis[now.step + 1][v] = 1;
            }
        }
    }
}
void solve()
{
    bfs(1);
    if (!cnt[k][n])
    {
        cout << "Ming had been tricked!" << endl;
        return;
    }
    else
    {
        cout << cnt[k][n] - 1 << "/" << cnt[k][n] << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        pre();
        solve();
    }
    return 0;
}