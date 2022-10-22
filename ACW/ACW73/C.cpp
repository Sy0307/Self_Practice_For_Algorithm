#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
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
int dis[maxn];
vector<pii> g[maxn];
void get_dis(int x, int fa, int val)
{
    dis[x] = dis[fa] + val;
    for (auto &t : g[x])
    {
        if (t.first == fa)
            continue;
        get_dis(t.first, x, t.second);
    }
}
void solve()
{
    int n;
    cin >> n;
    ll tot = 0;
    fr(i, 1, n -1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tot += c * 2;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    get_dis(1, -1, 0);
    ll ans = 0;
    fr(i, 1, n)
    {
        ans = max(ans, dis[i]);
    }
    cout << tot - ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}