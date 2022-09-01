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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> a[i];
    vector<ll> inv(n);
    inv[1] = 1;
    for (int i = 2; i < n; i++)
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;

    vector<ll> dp(n), sum(n + 1);
    dp[n - 1] = 0, sum[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = ((sum[i + 1] - sum[i + a[i] + 1] + mod + 1) % mod * inv[a[i]] + 1) % mod;
        sum[i] = (sum[i + 1] + dp[i]) % mod;
    }
    cout << dp[0] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}