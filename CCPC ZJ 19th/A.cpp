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

void solve()
{
    int a, b;
    cin >> a >> b;
    int dff = (b - a);
    if (dff == 0)
    {
        cout << 0 << endl;
        return;
    }
    else if (dff > 0)
    {
        if (dff & 1)
            cout << 1 << endl;
        else if ((dff / 2) & 1)
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }
    else
    {
        dff = abs(b - a);
        if (dff & 1)
            cout << 2 << endl;
        else
            cout << 1 << endl;
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