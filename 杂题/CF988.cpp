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
int a, n, m;
int rain[maxn],dp[maxn];
int w[maxn];
void init()
{
    cin >> a >> n >> m;
    fr(i, 1, n)
    {
        int l, r;
        cin >> l >> r;
        fr(j, l + 1, r)
        {
            rain[j]++;
        }
    }
    const int INF = 1e9;
    fill(w, w + maxn, INF);
    fr(i, 1, m)
    {
        int a, b;
        cin >> a >> b;
        w[a] = min(w[a], b);
    }
    fill(dp, dp + maxn, INF);
    int jud = dp[0];
    // cout<<jud<<endl;
    dp[0] = 0;
    fr(i, 1, a)
    {
        if(rain[i])
        {
            for(int j = i-1;j>=0;j--)
            {
                if(dp[j] != jud)
                {
                    dp[i] = min(dp[i], dp[j] + w[j]*(i-j));
                }
            }
        }
        else
        {
            dp[i] = dp[i-1];
        }
    }
    if(dp[a]!=jud)
    {
        cout<<dp[a]<<endl;
    }
    else cout<<-1<<endl;
}
void solve()
{
    init();
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