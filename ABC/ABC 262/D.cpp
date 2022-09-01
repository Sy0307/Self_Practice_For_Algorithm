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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

ll dp[110][110][110];
void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> a(n);
    fr(i, 0, n - 1)
    {
        cin >> a[i];
    }
    fr(i, 1, n)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        fr(j, 0, n - 1)
        {
            fr(k, 0, i)
            {
                fr(l, 0, i - 1)
                {
                    dp[j + 1][k][l] = (dp[j + 1][k][l] + dp[j][k][l]) % mod;
                    if (k != i)
                        dp[j + 1][k + 1][(l + a[j]) % i] = (dp[j + 1][k + 1][(l + a[j]) % i] + dp[j][k][l]) % mod;
                }
            }
        }
        ans = (ans + dp[n][i][0]) % mod;
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}