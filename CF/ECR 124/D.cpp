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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[maxn];
map<pii, int> mp;
pii a[maxn], ans[maxn];
void solve()
{
    cin >> n;
    fr(i, 1, n)
    {
        int x, y;
        cin >> x >> y;
        mp[{x, y}] = i;
        a[i] = {x, y};
    }
    queue<int> q;
    fr(i, 1, n)
    {
        int x = a[i].first, y = a[i].second;
        fr(j, 0, 3)
        {
            int nx = x + dx[j], ny = y + dy[j];
            if (!mp.count({nx, ny}) && !vis[mp[{x, y}]])
            {
                vis[mp[{x, y}]] = 1;
                ans[mp[{x, y}]] = {nx, ny};
                q.push(mp[{x, y}]);
            }
        }
    }
    while (q.size())
    {
        int t = q.front();
        q.pop();
        int x = a[t].first, y = a[t].second;
        fr(j, 0, 3)
        {
            int nx = x + dx[j], ny = y + dy[j];
            int k = mp[{nx, ny}];
            if (vis[k] || !mp.count({nx, ny}))
                continue;
            q.push(k);
            vis[k] = 1;
            ans[k] = ans[t];
        }
    }
    fr(i, 1, n)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
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
