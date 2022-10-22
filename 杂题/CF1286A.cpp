#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
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

int n;
void solve()
{
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    int vis[110] = {0};
    fr(i, 1, n)
    {
        cin >> a[i];
        vis[a[i]]++;
    }
    int odd = 0, even = 0;
    int dp[n + 1][n + 1][n + 1][2];
    fr(i, 1, n)
    {
        if (vis[i] == 0)
        {
            if (i & 1)
                odd++;
            else
                even++;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    int tot = 0;
    if (a[1] == 0)
    {
        tot++;
        dp[1][1][0][1] = 0;
        dp[1][0][1][0] = 0;
    }
    else
        dp[1][0][0][a[1] & 1] = 0;
    fr(i, 2, n)
    {
        if (a[i] == 0)
        {
            tot++;
            fr(j, 0, min(odd, tot))
            {
                if (tot - j > even)
                    continue;
                if (j > 0)
                    dp[i][j][tot - j][1] = min(dp[i - 1][j - 1][tot - j][1], dp[i - 1][j - 1][tot - j][0] + 1);
                if (tot - j - 1 >= 0)
                    dp[i][j][tot - j][0] = min(dp[i - 1][j][tot - j - 1][0], dp[i - 1][j][tot - j - 1][1] + 1);
            }
        }
        else
        {
            int sign = (a[i] & 1);
            fr(j, 0, min(tot, odd))
            {
                if (tot - j > even)
                    continue;
                dp[i][j][tot - j][sign] = min(dp[i - 1][j][tot - j][sign], dp[i - 1][j][tot - j][sign ^ 1] + 1);
            }
        }
    }

    cout << min(dp[n][odd][even][0], dp[n][odd][even][1]) << endl;
}
signed main()
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