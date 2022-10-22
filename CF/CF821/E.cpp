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

int64_t a[151][151];
int64_t get(ll t, int x, int y)
{
    memset(a, 0, sizeof(a));
    a[0][0] = max((ll)(t - (x + y) + 1), 0ll);
    fr(i, 0, x)
    {
        fr(j, 0, y)
        {
            a[i + 1][j] += a[i][j] / 2;
            a[i][j + 1] += (a[i][j] + 1) / 2;
        }
    }
    return a[x][y];
}
void solve()
{
    ll t, x, y;
    cin >> t >> x >> y;
    if (get(t, x, y) - get(t - 1, x, y) > 0)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}
int main()
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