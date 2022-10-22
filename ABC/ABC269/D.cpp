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

map<pii, int> mp;
int n;
int dx[6] = {0, 1, 1, -1, -1, 0};
int dy[6] = {1, 0, 1, 0, -1, -1};
vector<pii> a;
map<pii, int> vis;
void dfs(int x, int y)
{
    fr(i, 0, 5)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!vis[{nx, ny}] && mp[{nx, ny}])
        {
            vis[{nx, ny}] = 1;
            dfs(nx, ny);
        }
    }
}
void solve()
{
    cin >> n;
    int ans = 0;
    mp.clear();
    fr(i, 1, n)
    {
        // cout << n << endl;
        int x, y;
        cin >> x >> y;
        mp[{x, y}] = 1;
        a.push_back({x, y});
    }
    fr(i, 0, n-1)
    {
        int x = a[i].first;
        int y = a[i].second;
        if (!vis[{x, y}])
        {
          //  cout<<x<<" "<<y<<endl;
            vis[{x, y}] = 1;
            ans++;
            dfs(x, y);
        }
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}