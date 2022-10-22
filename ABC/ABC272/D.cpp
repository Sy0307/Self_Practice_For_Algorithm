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

int n, m;
struct node
{
    int x, y, step;
};
vector<pii> d;
void init()
{
    fr(i, 0, (int)sqrt(m) + 1)
    {
        fr(j, 0, (int)sqrt(m) + 1)
        {
            if (i * i + j * j == m)
            {
                d.push_back({i, j});
            }
        }
    }
    int cnt = d.size();
    for (int i = 0; i < cnt; i++)
    {
        auto now = d[i];
        d.push_back({-now.first, now.second});
        d.push_back({-now.first, -now.second});
        d.push_back({now.first, -now.second});
    }
}
bool vis[411][411];
int mp[411][411];
bool check(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n)
        return false;
    return true;
}
void solve()
{
    cin >> n >> m;
    init();
    queue<node> q;
    q.push({1, 1, 0});
    fr(i,1,n)
    {
        fr(j,1,n)
        {
            mp[i][j] = -1;
        }
    }
    mp[1][1] = 0;
    //  cout << d.size() << endl;
    while (q.size())
    {
        // cout<<"!"<<endl;
        auto now = q.front();
        q.pop();
        for (auto i : d)
        {
            int x = now.x + i.first;
            int y = now.y + i.second;
            // cout<<x<<" "<<y<<endl;
            if (!check(x, y) || (x == 1 && y == 1))
                continue;
            if (vis[x][y])
                continue;
            vis[x][y] = 1;
            q.push({x, y, now.step + 1});
            if (mp[x][y] == -1)
                mp[x][y] = now.step + 1;
        }
    }
    fr(i, 1, n)
    {
        fr(j, 1, n)
        {
            cout << mp[i][j] << " \n"[j == n];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}