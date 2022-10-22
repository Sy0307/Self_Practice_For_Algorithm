#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 5050;
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

#define int long long
int n, x, y;
vector<int> pos;
int dp[maxn][maxn];
string a, b;
int get(int l, int r)
{
    if (l + 1 == r)
    {
        return min(2 * y, x);
    }
    return min(y, x * (r - l));
}
const ll INF = 1e18;

int dfs(int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    ll res = INF;
    res = min(res, dfs(l + 1, r - 1) + get(pos[l], pos[r]));
    res = min(res, dfs(l, r - 2) + get(pos[r - 1], pos[r]));
    res = min(res, dfs(l + 2, r) + get(pos[l], pos[l + 1]));
    return dp[l][r] = res;
}
void solve()
{
    cin >> n >> x >> y;
    cin >> a;
    a = "!" + a;
    cin >> b;
    b = "!" + b;
    pos.clear();
    fr(i, 0, n)
        fr(j, 0, n)
            dp[i][j] = -1;
    fr(i, 1, n)
    {
        if (a[i] != b[i])
        {
            pos.push_back(i);
        }
    }
    if (pos.size() & 1)
    {
        cout << -1 << endl;
        return;
    }
    if (!pos.size())
    {
        cout << 0 << endl;
        return;
    }
    if (pos.size() == 2)
    {
        int ans;
        if (pos[0] + 1 == pos[1])
        {
            ans = min(2 * y, x);
        }
        else
            ans = min(y, x * (pos[1] - pos[0]));
        cout << ans << endl;
        return;
    }
    if (y <= x)
    {
        cout << pos.size() / 2 * y << endl;
    }
    else
        cout << dfs(0, pos.size() - 1) << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}