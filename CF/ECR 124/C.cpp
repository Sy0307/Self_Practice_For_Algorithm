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
const int INF = 1e9 + 100;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(a);
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    fr(i, 1, n)
    {
        cin >> b[i];
    }
    ll ans = abs(a[1] - b[1]) + abs(a[n] - b[n]);
    ans = min(ans, abs(a[1] - b[n]) + abs(a[n] - b[1]));
    int a1 = INF, an = INF, b1 = INF, bn = INF;
    fr(i, 1, n)
    {
        a1 = min(abs(a[1] - b[i]), a1);
        an = min(abs(a[n] - b[i]), an);
        b1 = min(abs(b[1] - a[i]), b1);
        bn = min(abs(b[n] - a[i]), bn);
    }
    ans = min(ans, abs(a[1] - b[1]) + bn + an);
    ans = min(ans, abs(a[n] - b[n]) + b1 + a1);
    ans = min(ans, abs(a[1] - b[n]) + b1 + an);
    ans = min(ans, abs(a[n] - b[1]) + bn + a1);
    ans = min(a1 + an + b1 + bn, ans);
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