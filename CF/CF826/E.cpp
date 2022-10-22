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

int dp[maxn];
int a[maxn];
void solve()
{
    int n;
    cin >> n;
    fr(i, 1, n)
    {
        cin >> a[i];
        dp[i] = 0;
    }
    if (n == 1)
    {
        cout << "NO" << endl;
        return;
    }
    dp[0] = 1;
    // dp[1] = 1;
    fr(i, 1, n)
    {
        if (dp[i - 1])
        {
            if (i + a[i] <= n)
            {
                dp[i + a[i]] = 1;
            }
        }
        if (i - a[i] - 1 >= 0)
        {
            dp[i] |= dp[i - a[i] - 1];
        }
    }

    if (dp[n])
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}
signed main()
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