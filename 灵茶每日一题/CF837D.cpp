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
#define int ll

int dp[2][210][10010];
int make(int x, int num)
{
    int cnt = 0;
    while (x % num == 0)
    {
        x /= num;
        cnt++;
    }
    return cnt;
}
void solve()
{
    // int n, k;
    // cin >> n >> k;
    // vector<int> a(n + 1), c2(n + 1), c5(n + 1);
    // fr(i, 1, n)
    // {
    //     cin >> a[i];
    // }
    array<int, 2> cnt;
    cnt.fill(0);
    // cin>>cnt<<endl;
    // cout<<cnt.size()<<endl;
    // memset(dp, -1, sizeof(dp));
    // dp[1][0][0] = 0;
    // int sum = 0;
    // fr(i, 1, n)
    // {
    //     c2[i] = make(a[i], 2);
    //     c5[i] = make(a[i], 5);
    //     //cout<<c2[i]<<" "<<c5[i]<<endl;
    //     sum += c5[i];
    // }
    // int s = 0, t = 1;
    // fr(i, 1, n)
    // {
    //     int x = c2[i];
    //     int y = c5[i];
    //     for (int j = 0; j <= i && j <= k; j++)
    //     {
    //         for (int p = 0; p <= sum; p++)
    //         {
    //             dp[s][j][p] = dp[t][j][p];
    //             if (j >= 1 && p - y >= 0 && dp[t][j - 1][p - y] >= 0)
    //             {
    //                 dp[s][j][p] = max(dp[s][j][p], dp[t][j - 1][p - y] + x);
    //             }
    //         }
    //     }
    //     swap(s, t);
    // }
    // int ans = 0;
    // fr(i, 0, sum)
    // {
    //     ans = max(ans,min(i,dp[t][k][i]));
    // }
    // cout<<ans<<endl;
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