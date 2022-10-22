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

int n, k;
vector<int> tree[maxn];
int p[maxn];
void solve()
{
    cin >> n >> k;
    fr(i, 0, n)
    {
        tree[i].clear();
    }
    p[1] = 1;
    fr(i, 2, n)
    {
        int x;
        cin >> x;
        p[i] = x;
        tree[x].push_back(i);
    }
    int l = 1, r = n;
    function<int(int, const int, int&)> dfs = [&](int x, const int h, int &ops) ->int
    {
        int maxd = 0;
        for (auto &i : tree[x])
        {
            maxd = max(maxd, dfs(i, h, ops));
        }
        if (p[x] == 1)
            return 0;
        if (++maxd >= h)
            maxd = 0, ops++;
        return maxd;
    };
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        int ops = 0;
        dfs(1, mid, ops);
        if (ops <= k)
        {
            r = mid - 1;
        }
        else if (ops > k)
        {
            l = mid + 1;
        }
    }
    cout << r + 1 << endl;
}
signed main()
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