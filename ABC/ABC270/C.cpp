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

int x, y;
bool suc = 0;
vector<int> edge[maxn];
void dfs(int now, int fa, vector<int> &path)
{
    if (suc)
        return;
    if (now == y)
    {
        for (auto &k : path)
        {
            cout << k << " ";
        }
        cout << endl;
        suc = 1;
        return;
    }
    for(auto &k:edge[now])
    {
        if(k==fa)
            continue;
        path.push_back(k);
        dfs(k, now, path);
        path.pop_back();
    }
}
void solve()
{
    int n;
    cin >> n >> x >> y;
    fr(i, 2, n)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> ans(0,0);
    ans.push_back(x);
    dfs(x,-1,ans);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}