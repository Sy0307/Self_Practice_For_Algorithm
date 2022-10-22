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

bool g[21][21];
ll f[1 << 20][20], n, m, k;
void solve()
{
    cin >> n >> m;
    fr(i, 0, m - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a][b] = g[b][a] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        f[1 << i][i] = 1;
    }
    ll ans = 0;
    fr(i, 1, (1 << n) - 1)
    {
        fr(j, 0, n - 1)
        {
            if (!f[i][j])
                continue;
            fr(k, 0, n - 1)
            {
                if (!g[k][j])
                    continue;
                if ((i & -i) > (1 << k))
                    continue;
                if ((1 << k) & i)
                {
                    if (1 << k == (i & -i))
                    {
                        ans += f[i][j];
                    }
                }
                else
                    f[i | 1 << k][k] += f[i][j];
            }
        }
    }
    cout << (ans - m) / 2 << endl;
}
int main()
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