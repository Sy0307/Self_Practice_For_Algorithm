#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
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

ll n, m, a, b, k, x, y;
ll f(ll k)
{
    return a + b * k + (1 + k) * k / 2 * x;
}

ll check(ll l, ll r)
{
    while (l + 2 < r)
    {
        ll mid1 = (l + r) >> 1;
        ll mid2 = mid1 + 1;
        if (f(mid1) < f(mid2))
        {
            l = mid1;
        }
        else
        {
            r = mid2;
        }
    }
    return f(l + 1);
}
void solve()
{
    cin >> n >> m;
    a = 0, b = 0;
    ll ans = -LLONG_MAX;
    fr(i, 1, n)
    {
        // ll x, y;
        cin >> x >> y;
        if (x >= 0)
        {
            ans = max(ans, f(1));
            ans = max(ans, f(y));
        }
        else
        {
            ans = max(ans, check(0, y + 1));
        }
        a = f(y);
        b += x * y;
    }
    cout << ans << endl;
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