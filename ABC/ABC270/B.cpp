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

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    if (x * y < 0)
    {
        cout << abs(x) << endl;
        return;
    }
    else if (abs(x) <= abs(y))
    {
        cout << abs(x) << endl;
    }
    else if (z * x < 0)
    {
        cout << 2 * abs(z) + abs(x) << endl;
    }
    else if (abs(z) <= abs(y))
    {
        cout << abs(x) << endl;
    }
    else
        cout << -1 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}