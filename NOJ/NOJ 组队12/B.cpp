#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 998244353;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

ll n, a[200010], inv[200010], pre[200010], dp[200010];

void solve()
{
    cin >> n;
    inv[0] = inv[1] = 1;
    fr(i, 2, maxn)
    {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    fr(i, 1, n - 1)
    {
        cin >> a[i];
    }
    dp[n] = 0;
    pre[n] = 0;
    ford(i, n - 1, 1)
    {
        dp[i] = 1 + (pre[i + 1] - pre[i + a[i] + 1] + mod) * inv[a[i] + 1] % mod;
        dp[i] = dp[i] * (a[i] + 1) % mod * inv[a[i]] % mod;
        pre[i] = (pre[i + 1] + dp[i]) % mod;
    }
    cout << dp[1] << "\n";
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