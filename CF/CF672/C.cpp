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
    int n, q;
    cin >> n >> q;
    int a[n + 1] = {0};
    int f[n + 1][2] = {0};
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    fr(i, 1, n)
    {
        f[i][0] = max(f[i - 1][0], f[i - 1][1] - a[i]);
        f[i][1] = max(f[i - 1][1], f[i - 1][0] + a[i]);
    }
    cout << max(f[n][0], f[n][1]) << endl;
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