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

int n, m;
char mp[510][510];
int dp[510][510];
int tobe;

bool check(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;
    return true;
}
int dfs(int x, int y)
{
    if (dp[x][y] != -1)
        return dp[x][y];
    if (mp[x][y] == 'A')
        return 1;
    if (mp[x][y] == 'B')
        return 2;
    if (x == n && y == m)
        return 0;
    if ((x + y) % 2 == 0)
    {
        int k1 = 0, k2 = 0;
        if (check(x + 1, y))
        {
            k1 = dfs(x + 1, y);
            if (k1 == tobe)
                return dp[x][y] = k1;
        }

        if (check(x, y + 1))
        {
            k2 = dfs(x, y + 1);
            if (k2 == tobe)
                return dp[x][y] = k2;
        }
        if (k1 == 0)
            return dp[x][y] = k2;
        else
            return dp[x][y] = k1;
    }
    else
    {
        int k1 = 0, k2 = 0;
        if (check(x + 1, y))
        {
            k1 = dfs(x + 1, y);
            if (k1 != tobe)
                return dp[x][y] = k1;
        }

        if (check(x, y + 1))
        {
            k2 = dfs(x, y + 1);
            if (k2 != tobe)
                return dp[x][y] = k2;
        }
        if (k1 == 0)
            return dp[x][y] = k2;
        else
            return dp[x][y] = k1;
    }
}
void init()
{
    fr(i, 1, n)
    {
        fr(j, 1, m)
        {
            dp[i][j] = -1;
        }
    }
}
// win = 1
// lose = 2
// draw = 0
void solve()
{
    cin >> n >> m;
    fr(i, 1, n)
    {
        fr(j, 1, m)
        {
            cin>>mp[i][j];
        }
    }
    init();
    tobe = 1;
    if (dfs(1, 1) == tobe)
    {
        cout << "yes ";
    }
    else
        cout << "no ";

    init();
    tobe = 0;
    if (dfs(1, 1) == tobe)
    {
        cout << "yes ";
    }
    else
        cout << "no ";

    init();
    tobe = 2;
    if (dfs(1, 1) == tobe)
    {
        cout << "yes";
    }
    else
        cout << "no";

    cout << endl;
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