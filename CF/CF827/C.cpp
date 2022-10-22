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

char mp[10][10];
bool check_row(int x, char c)
{
    fr(i, 1, 8)
    {
        if (mp[x][i] != c)
            return false;
    }
    return true;
}
bool check_col(int y, char c)
{
    fr(i, 1, 8)
    {
        if (mp[i][y] != c)
            return false;
    }
    return true;
}
void solve()
{
    fr(i, 1, 8)
    {
        fr(j, 1, 8)
        {
            cin >> mp[i][j];
        }
    }

    fr(i, 1, 8)
    {
        if (check_row(i, 'R'))
        {
            cout << "R" << endl;
            return;
        }
    }
    fr(i, 1, 8)
    {
        if (check_col(i, 'B'))
        {
            cout << "B" << endl;
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