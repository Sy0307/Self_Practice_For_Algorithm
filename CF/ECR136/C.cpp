#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 100;
const int mod = 998244353;
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

ll f[maxn];
ll c[maxn][maxn];
void init()
{
    // inv[1] = 1;
    // fr(i, 2, maxn - 1)
    // {
    //     inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    // }

    fr(i, 0, maxn - 1)
    {
        c[i][0] = 1;
        fr(j, 1, i)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
    f[2] = 1;
    f[4] = 3;
    fr(i, 6, maxn - 1)
    {
        f[i] = (c[i - 1][i / 2] + c[i - 4][i / 2 - 3] + f[i - 4]) % mod;
    }
}
#define int ll
void solve()
{
    int n;
    cin >> n;
    int tot = c[n][n / 2];
    int win = f[n];
    int lose = (tot - win - 1 + mod) % mod;
    cout << win << " " << lose << " " << 1 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    init();
    while (T--)
    {
        solve();
    }
    return 0;
}