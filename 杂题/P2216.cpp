#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1010;
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

int stmax[maxn][maxn][12], stmin[maxn][maxn][12];
int LOG;
int a, b, n;
int querymax(int x, int y, int ex, int ey)
{
    int t1 = stmax[x][y][LOG];
    int t2 = stmax[ex - (1 << LOG) + 1][ey - (1 << LOG) + 1][LOG];
    int t3 = stmax[ex - (1 << LOG) + 1][y][LOG];
    int t4 = stmax[x][ey - (1 << LOG) + 1][LOG];
    return max({t1, t2, t3, t4});
}
int querymin(int x, int y, int ex, int ey)
{
    int t1 = stmin[x][y][LOG];
    int t2 = stmin[ex - (1 << LOG) + 1][ey - (1 << LOG) + 1][LOG];
    int t3 = stmin[ex - (1 << LOG) + 1][y][LOG];
    int t4 = stmin[x][ey - (1 << LOG) + 1][LOG];
    return min({t1, t2, t3, t4});
}
void solve()
{
    cin >> a >> b >> n;
    int x;
    fr(i, 1, a)
    {
        fr(j, 1, b)
        {
            cin >> x;
            stmax[i][j][0] = stmin[i][j][0] = x;
        }
    }
    LOG = (int)(log2(n));

    fr(k, 1, 11)
    {
        for (int i = 1; i + (1 << k) - 1 <= a; i++)
        {
            for (int j = 1; j + (1 << k) - 1 <= b; j++)
            {
                stmax[i][j][k] = max({stmax[i][j][k - 1],
                                      stmax[i + (1 << (k - 1))][j][k - 1],
                                      stmax[i][j + (1 << (k - 1))][k - 1],
                                      stmax[i + (1 << (k - 1))][j + (1 << (k - 1))][k - 1]});
                stmin[i][j][k] = min({stmin[i][j][k - 1],
                                      stmin[i + (1 << (k - 1))][j][k - 1],
                                      stmin[i][j + (1 << (k - 1))][k - 1],
                                      stmin[i + (1 << (k - 1))][j + (1 << (k - 1))][k - 1]});
            }
        }
    }

    int ans = 0x3f3f3f3f;
    fr(i, 1, a - n + 1)
    {
        fr(j, 1, b - n + 1)
        {
            ans = min(ans, querymax(i, j, i + n - 1, j + n - 1) -
                               querymin(i, j, i + n - 1, j + n - 1));
            // cout<<ans<<endl;
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}