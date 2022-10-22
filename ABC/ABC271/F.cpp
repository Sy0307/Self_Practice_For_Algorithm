#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 40;
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

#define int ll
unordered_map<int, int> f[maxn][maxn];
int a[maxn][maxn];
int ans, n, m;
void dfs1(int x, int y, int v)
{
    if (x + y == n)
    {
        f[x][y][v]++;
        return;
    }
    else
    {
        if (x + y < n)
        {
            dfs1(x + 1, y, v ^ a[x + 1][y]);
            dfs1(x, y + 1, v ^ a[x][y + 1]);
        }
    }
}

void dfs2(int x,int y,int v)
{
    if (x + y == n)
    {
        ans += f[x][y][v^a[x][y]];
        return;
    }
    else
    {
        if (x + y > n)
        {
            dfs2(x - 1, y, v ^ a[x - 1][y]);
            dfs2(x, y - 1, v ^ a[x][y - 1]);
        }
    }
}
void solve()
{
    cin >> n;
    fr(i, 1, n)
    {
        fr(j, 1, n)
        {
            cin >> a[i][j];
        }
    }
    dfs1(1, 1, a[1][1]);
    dfs2(n, n, a[n][n]);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}