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

char mp[101][101];
int a[101][101];
int b[101][101];
int cnt1 = 1, cnt2 = 1;
int n, m;
vector<int> edge[maxn];
bool vis[maxn];
int match[maxn];
void ADD(int x, int y)
{
    edge[x].push_back(y);
}
bool dfs(int x)
{
    for (auto &k : edge[x])
    {
        if (!vis[k])
        {
            vis[k] = 1;
            int t = match[k];
            if (!t || dfs(t))
            {
                match[k] = x;
                return 1;
            }
        }
    }
    return 0;
}
void solve()
{
    cin >> n >> m;
    fr(i, 1, n)
    {
        fr(j, 1, m)
        {
            cin >> mp[i][j];
        }
    }
    fr(i, 1, n)
    {
        fr(j, 1, m)
        {
            if (mp[i][j] == '*')
            {
                a[i][j] = cnt1;
            }
            else
                cnt1++;
        }
        cnt1++;
    }
    fr(j, 1, m)
    {
        fr(i, 1, n)
        {
            if (mp[i][j] == '*')
            {
                b[i][j] = cnt2;
            }
            else
                cnt2++;
        }
        cnt2++;
    }
    fr(i, 1, n)
    {
        fr(j, 1, m)
        {
            if (mp[i][j] == '*')
            {
                ADD(a[i][j], b[i][j]);
            }
        }
    }
    int ans = 0;
    fr(i, 1, cnt1)
    {
        memset(vis, 0, sizeof(vis));
        if (dfs(i))
            ans++;
    }
    cout << ans << endl;
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