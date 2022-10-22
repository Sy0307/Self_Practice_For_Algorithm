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

const int INF = 1e9 + 20;

vector<vector<int>> dis[200];
vector<vector<int>> g;
vector<pii> kk;
int n, m, k, q;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void bfs(int x, int y, vector<vector<int>> &dis)
{
    queue<pii> q;
    q.push({x, y});
    dis[x][y] = 0;
    while (q.size())
    {
        auto [x, y] = q.front();
        q.pop();
        fr(i, 0, 3)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny]==1)
                continue;
            if (dis[nx][ny] != INF)
            {
                continue;
            }
            dis[nx][ny] = dis[x][y] + 1;
            q.push({nx, ny});
        }
    }
}
void solve()
{
    cin >> n >> m >> k >> q;
    g = vector<vector<int>>(n + 2, vector<int>(m + 2,0));
    int cnt_k = 0;
    kk.resize(k + 1);
    fr(i, 1, k)
    {
        int x, y;
        cin >> x >> y;
        kk[i].first = x;
        kk[i].second = y;
        g[x][y] = 1;
    }

    fr(i, 1, k)
    {
        fr(j, 0, 3)
        {
            int nx = kk[i].first + dx[j], ny = kk[i].second + dy[j];
            if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny])
                continue;
            dis[++cnt_k] = vector<vector<int>>(n + 2, vector<int>(m + 2, INF));
            bfs(nx, ny, dis[cnt_k]);
        }
    }

    while (q--)
    {
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        int a = max(x1, x2), b = min(x1, x2), c = max(y1, y2), d = min(y1, y2);
        bool suc = 0;
        fr(i, 1, k)
        {
            int x = kk[i].first, y = kk[i].second;
            if (x >= b && x <= a && y >= d && y <= c)
            {
                suc = 1;
                // break;
            }
        }
        if (!suc)
        {
            cout << abs(x1 - x2) + abs(y1 - y2) << endl;
        }
        else
        {
            int ans = INF;
            fr(i, 1, cnt_k)
            {
                ans = min(ans, dis[i][x1][y1] + dis[i][x2][y2]);
            }
            if (ans == INF)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << ans << endl;
            }
        }
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