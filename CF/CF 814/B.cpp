#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 5e5 + 10;
const int mod = 10007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

ll dp[maxn], a[maxn];
void solve()
{
    ll n;
    cin >> n;
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    dp[1] = 0;
    dp[2] = 2;
    fr(i, 2, n)
    {
        dp[i + 1] = dp[i] * 2 + 10 * mod - dp[a[i]] + 2;
        dp[i + 1] %= mod;
    }
    cout << dp[n + 1] << endl;
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