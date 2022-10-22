#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
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

ll n, m, a[maxn];
bool check(ll x)
{
    ll tot = 0;
    fr(i, 1, n)
    {
        tot += min(a[i], x);
    }
    return tot <= m;
}
void solve()
{
    cin >> n >> m;
    // vector<int> a(n + 1);
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    ll l = 0, r = m + 1, ans = -1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    if (ans < 0)
    {
        return;
    }
    fr(i, 1, n) m -= min(a[i], ans), a[i] -= min(a[i], ans);
    fr(i, 1, n)
    {
        if (a[i] > 0 && m > 0)
        {
            a[i]--;
            m--;
        }
    }
    fr(i, 1, n)
    {
        cout << a[i] << " \n"[i == n];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}