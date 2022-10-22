#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 3e5 + 10;
const int mod = 1000000007;
#define inl inline
#define endl '\n'
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
// istream &operator>>(istream &in, vector<int> &v)
// {
//     for (auto &i : v)
//         in >> i;
//     return in;
// }
// ostream &operator<<(ostream &out, vector<int> &v)
// {
//     for (auto &i : v)
//         out << i << " ";
//     return out;
// }

#define int ll
ll dis[310][310];
int t, n, m, K;
bool st[maxn], is_good[maxn];
int fa[maxn];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool check(ll x)
{
    fr(i, 1, n)
    {
        fa[i] = i;
        st[i] = 0;
    }
    ll cnt = K;

    fr(i, 1, n)
    {
        if (is_good[i])
        {
            fr(j, 1, n)
            {
                if (is_good[j])
                {
                    if ((dis[i][j] / (t + 0.0)) <= x && dis[i][j] != 1e18)
                    {
                        int pa = find(i), pb = find(j);
                        if (pa != pb)
                            fa[pb] = pa, cnt--;
                    }
                }
                if ((2.0 * dis[i][j] / t) <= x && dis[i][j] != 1e18)
                    st[j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (!st[i])
            return false;
    if (cnt != 1)
        return false;
    return true;
}
void init()
{
    fr(i, 1, n)
    {
        fr(j, 1, n)
        {
            dis[i][j] = 1e18;
        }
    }
    fr(i, 1, n)
    {
        dis[i][i] = 0;
    }
}
void solve()
{
    cin >> n >> m >> K;

    cin >> t;
    init();
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = dis[b][a] = min(dis[a][b], c);
    }
    int x;
    fr(i, 1, K)
    {
        cin >> x;
        is_good[x] = 1;
    }
    if (t == 0)
    {
        cout << -1 << endl;
        return;
    }
    for (int k = 1; k <= n; k++) // floyd
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    int l = 1, r = 1e12; //二分
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (l == 1e12)
        l = -1;
    cout << l << '\n';
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