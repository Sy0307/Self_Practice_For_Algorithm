#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 3e5 + 10;
const int mod = 1000000007;
#define inl inline
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

#define int ll
struct edge
{
    int a, b, c;
} edge[maxn];
int dis[maxn];
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    fr(i, 1, m)
    {
        auto &[a, b, c] = edge[i];
        cin >> a >> b >> c;
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    fr(i, 1, k)
    {
        int x;
        cin >> x;
        auto [a, b, c] = edge[x];
        dis[b] = min(dis[b], dis[a] + c);
    }
    if (dis[n] > 1e18 / 2)
    {
        cout << -1 << endl;
    }
    else
        cout << dis[n] << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}