#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 5e5 + 10;
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
#define int ll
bool vis[maxn] = {0};
int primes[maxn], tot = 0;
void init()
{
    int cnt = 0;
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] * i < maxn; j++)
        {
            vis[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}
int lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    // vector<int> a(n + 1);
    vector<int> b(n + 1);
    // fr(i, 1, n)
    // {
    //     cin >> a[i];
    // }
    int now = m % mod;
    b[1] = now;
    now = 1;
    fr(i, 2, n)
    {
        if (!vis[i])
        {
            now = lcm(now, i);
        }
        int cnt = m / now;
        b[i] = (b[i - 1] * (cnt % mod)) % mod;
    }
    now = m % mod;
    int ans = 0;
    fr(i, 1, n)
    {
        ans = (ans + now - b[i] + mod) % mod;
        now = (now * (m%mod)) % mod;
    }
    cout << (ans +mod)%mod<< endl;
}
signed main()
{
    init();
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