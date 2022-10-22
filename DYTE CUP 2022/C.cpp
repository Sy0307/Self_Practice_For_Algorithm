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

int n;
map<int, int> mp1, mp2;
void solve()
{
    mp1.clear();
    mp2.clear();
    cin >> n;
    int x[4];
    int y[4];
    fr(i, 1, 3)
    {
        cin >> x[i]>>y[i];
        mp1[x[i]]++;
        mp2[y[i]]++;
    }
    int sx, sy, mx, my;
    fr(i, 1, 3)
    {
        if (mp1[x[i]] == 1)
        {
            sx = x[i];
        }
    }
    fr(i, 1, 3)
    {
        if (mp2[y[i]] == 1)
        {
            sy = y[i];
        }
    }
    fr(i, 1, 3)
    {
        if (mp1[x[i]] == 2)
        {
            mx = x[i];
        }
    }
    fr(i, 1, 3)
    {
        if (mp2[y[i]] == 2)
        {
            my = y[i];
        }
    }
    int ex, ey;
    cin >> ex >> ey;
    int dx = abs(sx - ex);
    int dy = abs(sy - ey);
    if ((mx == 1 || mx == n) && (my == 1 || my == n))
    {
        if ((ex == mx) || (ey == my))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        return;
    }
    else
    {
        if (dx % 2 == 0 && dy % 2 == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
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