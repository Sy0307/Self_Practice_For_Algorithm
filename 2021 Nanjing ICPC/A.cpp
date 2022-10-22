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

int a, b;
void solve()
{
    int n;
    cin >> n;
    cin >> a >> b;
    int d1 = a + b - 2;
    int d2 = a - 1 + n - b;
    int d3 = n - a + b - 1;
    int d4 = n - a + n - b;
    int minx = min({d1, d2, d3, d4});
    if (d1 == minx)
    {
        fr(i, 1, n - 1)
        {
            cout << "UL";
        }
        fr(i, 1, a - 1)
        {
            cout << "D";
        }
        fr(i, 1, b - 1)
        {
            cout << "R";
        }
    }
    else if (d2 == minx)
    {
        fr(i, 1, n - 1)
        {
            cout << "UR";
        }
        fr(i, 1, a - 1)
        {
            cout << "D";
        }
        fr(i, 1, n - b)
        {
            cout << "L";
        }
    }
    else if (d3 == minx)
    {
        fr(i, 1, n - 1)
        {
            cout << "DL";
        }
        fr(i, 1, n - a)
        {
            cout << "U";
        }
        fr(i, 1, b - 1)
        {
            cout << "R";
        }
    }
    else
    {
        fr(i, 1, n - 1)
        {
            cout << "DR";
        }
        fr(i, 1, n - a )
        {
            cout << "U";
        }
        fr(i, 1, n - b)
        {
            cout << "L";
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}