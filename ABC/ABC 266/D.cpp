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
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define ford(i, a, b) for(int i = a; i >= b; i--)
#define forall(i, a) for(auto &i : a)

ll table[maxn][7];
ll dp[maxn][7];
int maxt;
void solve()
{
    int n;cin >> n;
    fr(i, 1, n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        table[a][b+1] = c;
        maxt = max(maxt, a);
    }
    memset(dp, -0x3f, sizeof dp);
    dp[0][1] = 0;
    fr(i, 1, maxt)
    {
        fr(j, 1, 5)
        {
            int last = j - 1;
            int next = j + 1;
            dp[i][j] = dp[i - 1][j]+table[i][j];
            dp[i][j] = max(dp[i][j], dp[i - 1][next] + table[i][j]);
            dp[i][j] = max(dp[i][j], dp[i - 1][last] + table[i][j]);
        }
    }
    ll ans = 0;
    for (int i = 1;i <= 5;i++)
    {
        ans = max(ans, dp[maxt][i]);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}