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
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define ford(i, a, b) for(int i = a; i >= b; i--)
#define forall(i, a) for(auto &i : a)

set<pii> S;
ll n,m,a,b,c,d,e,f;
ll dp[510][510][510];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //    DEBUG();

    cin >> n >> m;
    cin >> a >> b >> c >> d >> e >> f;

    while (m--) {
        int a, b; cin >> a >> b;
        S.insert({ a, b });
    }

    dp[0][0][0] = 1;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n - i; j++)
            for (int k = 0; k <= n - i - j; k++) {
                if (!dp[i][j][k]) continue;

                ll cx = i * a + j * c + k * e;
                ll cy = i * b + j * d + k * f;

                ll nx = cx + a, ny = cy + b;
                if (!S.count({ nx, ny })) dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % mod;

                nx = cx + c, ny = cy + d;
                if (!S.count({ nx, ny })) dp[i][j + 1][k] = (dp[i][j + 1][k] + dp[i][j][k]) % mod;

                nx = cx + e, ny = cy + f;
                if (!S.count({ nx, ny })) dp[i][j][k + 1] = (dp[i][j][k + 1] + dp[i][j][k]) % mod;
            }

    ll ans = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n - i; j++)
            if (n - i - j >= 0)
                ans = (ans + dp[i][j][n - i - j]) % mod;
    cout << ans << endl;
    return 0;
}