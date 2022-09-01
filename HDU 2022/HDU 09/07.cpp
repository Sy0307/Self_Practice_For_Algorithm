#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
#define ad(x, y) x = (x + y) % mod
const int maxn = 5005;
const int mod = 998244353;
int n, group, r;
int dp[maxn][maxn];
int l[maxn];
vector<int> a;
void solve()
{
    cin >> n >> group >> r;
    a.resize(n + 1);
    for (int i = 0; i <= n + 2; i++)
    {
        for (int j = 0; j <= n + 2; j++)
        {
            dp[i][j] = 0;
        }
    }
    fr(i, 1, n)
    {
        l[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    fr(i, 1, n)
    {
        fr(j, 1, i - 1)
        {
            if (abs(a[i] - a[j]) < r)
            {
                l[i]++;
            }
        }
    }
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ad(dp[i][j], dp[i - 1][j - 1]);
            ad(dp[i][j], 1LL * dp[i - 1][j] * (j - l[i] % mod));
        }
    }

    // for(int i=1;i<=group;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout << dp[n][group] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}