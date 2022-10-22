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

#define int ll
void solve()
{
    int n, t, k;
    cin >> n >> t >> k;
    ll x = t - (2 * n - 2) * k;
    ll y = t - (2 * n - 1) * k;
    ll p = 4 * n * k;
    if (x <= 0)
    {
        cout << p << endl;
        return;
    }
    if (x > 0 && x <= k)
    {
        cout << p + x << endl;
        return;
    }
    if (x > k)
    {
        if (y - k <= 0)
        {
            cout << p + k << endl;
            return;
        }
        else
        {
            cout << p + y << endl;
            return;
        }
    }
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