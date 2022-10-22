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

// #define ll __int128_t
ll check(ll n)
{
    if (n == 0)
        return 0ll;
    __int128_t ans = 0;
    ll l = 0, r = n;
    while (l < r)
    {
        __int128_t mid = (l + r + 1) / 2;
        __int128_t t = (__int128_t)(mid)*mid;
        if (t <= n)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    ans = (l - 1) * 3;
    if ((__int128_t)l * l <= n)
        ans += 1;
    if (__int128_t(l) * (l + 1) <= n)
        ans += 1;
    if (__int128_t(l) * (l + 2) <= n)
        ans += 1;
    return ans;
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    cout << check(r) - check(l - 1) << endl;
    // cin >> l >> r;
    // cout << r - l << endl;
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