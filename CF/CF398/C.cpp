#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e6 + 10;
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
int root;
int w[maxn];
vector<int> g[maxn];
int id;
int ct[3];
int sum = 0;
void dfs(int x, int fa)
{
    for (auto &t : g[x])
    {
        if (t == fa)
            continue;
        dfs(t,x);
        w[x] += w[t];
    }
    if (w[x] == sum / 3 && x != root)
    {
        if (id > 1)
            return;
        w[x] = 0;
        ct[id++] = x;
    }
}
void solve()
{
    cin >> n;
    fr(i, 1, n)
    {
        int a, b;
        cin >> a;
        cin >> w[i];
        sum += w[i];
        if (a)
        {
            g[a].push_back(i);
        }
        else
        {
            root = i;
        }
    }
    if (sum % 3)
    {
        cout << -1 << endl;
    }
    else
    {
        dfs(root, -1);
        if (id == 2)
        {
            cout << ct[0] << " " << ct[1] << endl;
        }
        else
            cout << -1 << endl;
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