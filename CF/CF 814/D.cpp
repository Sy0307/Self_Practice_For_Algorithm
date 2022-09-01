#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

void solve()
{
    int n;
    cin >> n;
    int a[n + 1];
    vector<int> k(n + 1, 0);
    map<int, int> mp;
    mp[0] = 0;
    vector<int> dp(n + 1, INT_MAX - 1);
    dp[0] = 0;
    fr(i, 1, n)
    {
        cin >> a[i];
        k[i] = k[i - 1] ^ a[i];
    }

    fr(i, 1, n)
    {
        if (a[i] == 0)
            dp[i] = min(dp[i], dp[i - 1]);
        else
            dp[i] = min(dp[i], dp[i - 1] + 1);
        if (mp.count(k[i]))
        {
            dp[i] = min(dp[i], mp[k[i]] + i - 1);
        }
        mp[k[i]] = min(mp[k[i]], dp[i] - i);
    }
    cout << dp[n] << "\n";
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