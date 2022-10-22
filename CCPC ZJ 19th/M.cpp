#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
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
const int cnum = 73, snum = 100;
int num_of_hole = 0;
char mp[1010][1010];
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool vis[1010][1010] = {0};
void dfs(int x, int y, int &cnt)
{
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y] || mp[x][y] == '#')
        return;
    cnt++;
    vis[x][y] = 1;

    fr(i, 0, 3)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (vis[nx][ny] || mp[nx][ny] == '#')
            continue;
        dfs(nx, ny, cnt);
    }
}
bool check(int x, int y)
{
    // if (x + 3 > n || y <= 1 || y + 3 > m)
    //     return 0;
    // if (mp[x][y - 1] != '#')
    //     return 0;
    // if (mp[x][y + 2] != '#')
    //     return 0;
    // if (mp[x + 3][y - 1] != '#')
    //     return 0;
    // if (mp[x + 3][y + 2] != '#')
    //     return 0;
    for (int i = 0; i < 2; i++)
    {
        if (mp[x][y + i] != '.')
            return 0;
    }
    for (int i = -1; i < 3; i++)
    {
        if (mp[x + 1][y + i] != '.')
            return 0;
    }
    for (int i = -1; i < 3; i++)
    {
        if (mp[x + 2][y + i] != '.')
            return 0;
    }
    for (int i = 0; i < 2; i++)
    {
        if (mp[x + 3][y + i] != '.')
            return 0;
    }
    // num_of_hole++;
    return 1;
}
void solve()
{
    cin >> n >> m;
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == '#')
                tot++;
            else if (!vis[i][j])
            {
                int cnt = 0;
                dfs(i, j, cnt);
                if (cnt == 12)
                {
                    if (check(i, j))
                    {
                        num_of_hole++;
                    }
                }
            }
        }
    }
    // fr(i, 1, n)
    // {
    //     fr(j, 1, m)
    //     {
    //         if (check(i, j))
    //         {
    //             num_of_hole++;
    //         }
    //     }
    // }
    //  cout<<num_of_hole<<endl;
  //  cout << num_of_hole << endl;
    int x = num_of_hole * 100 - tot;
    x /= 54;
    int y = num_of_hole - (100 * num_of_hole - tot) / 27;
    cout << x << " " << y << endl;
    // 146x+100y= tot ;
    // 2x + y = num_of_hole;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}