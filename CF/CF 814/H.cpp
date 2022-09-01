#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 4e6 + 10;
const int maxm = 2000 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

int c[maxn], d[maxn];
int vis[maxm][maxm], g[maxm][maxm];
void solve()
{
    int a, b, x, p;
    cin >> a >> b >> x >> p;
    c[1] = a % p, c[2] = b % p;
    d[1] = c[1], d[2] = c[2];
    vis[c[2]][c[1]] = 1;
    g[c[2]][c[1]] = 1;
    int t = p * p;
    int n1 = t, n2 = t;
    int s1 = 1, s2 = 1;
    fr(i, 3, t)
    {
        c[i] = (c[i - 1] + c[i - 2]) % p;
        if (vis[c[i]][c[i - 1]])
        {
            n1 = i - 2;
            s1 = vis[c[i]][c[i - 1]];
            break;
        }
        vis[c[i]][c[i - 1]] = i - 1;
    }
    fr(i, 3, t)
    {
        d[i] = (ll)d[i - 1] * d[i - 2] % p;
        if (g[d[i]][d[i - 1]])
        {
            n2 = i - 2;
            s2 = g[d[i]][d[i - 1]];
            break;
        }
        g[d[i]][d[i - 1]] = i - 1;
    }
    int ans1, ans2;
    if (x < s1)
    {
        ans1 = c[x];
    }
    else
    {
        ans1 = c[s1 - 1 + (x - (s1 - 1) - 1) % (n1 - s1 + 1) + 1];
    }

    if (x < s2)
    {
        ans2 = d[x];
    }
    else
    {
        ans2 = d[s2 - 1 + (x - (s2 - 1) - 1) % (n2 - s2 + 1) + 1];
    }

    cout << ans1 << " " << ans2 << endl;
}
int main()
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