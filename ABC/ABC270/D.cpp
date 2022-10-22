#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define inl inline
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

int dp[10010];
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    fr(i, 0, k - 1)
    {
        cin >> a[i];
    }
    fr(i, 0, n)
    {
        fr(j, 0, k - 1) if (a[j] <= i)
        {
            dp[i] = max(dp[i], i - dp[i - a[j]]);
        }
    }
    cout << dp[n] << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}