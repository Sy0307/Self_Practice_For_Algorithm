#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 998244353;
#define inl inline
#define endl '\n'
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

#define int long long
int n, m;
ll qmi(int a, int b, int p)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int calc(int x, int y)
{
    int sum1 = (x / 2) * y % mod * (y + 1) % mod * qmi(2, mod - 2, mod) % mod;
    int n1 = (y + 1) / 2, n2 = y / 2;
    if (x % 2)
    {
        int t = n1 % mod * n1 % mod;
        sum1 = (sum1 + t) % mod;
    }
    int a = (x - 1) / 2, b = x / 2;
    int sum2 = m * ((a % mod * a % mod + a) % mod * n1 % mod + b % mod * b % mod * n2 % mod) % mod;
    return (sum1 + sum2) % mod;
}

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << ((calc(b, d) - calc(a - 1, d) - calc(b, c - 1) + calc(a - 1, c - 1)) % mod + mod) % mod << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> n >> m;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}