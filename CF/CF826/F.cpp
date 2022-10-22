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

constexpr int INF = 1E9 + 100;
void solve()
{
    int n;
    cin >> n;

    vector<array<int, 5>> pts(2 * n);
    fr(i, 0, n - 1)
    {
        int l, r, c;
        cin >> l >> r >> c;
        pts[2 * i] = {l, r, c, i, 0};
        pts[2 * i + 1] = {r, l, c, i, 1};
    }

    sort(pts.begin(), pts.end());
    vector<int> ans(n, INF);

    fr(t, 0, 1)
    {
        array<int, 2> f[2];
        f[0] = f[1] = {-INF, -1};
        for (auto [x, y, c, i, o] : pts)
        {
            if (!o)
            {
                array g{y, c};
                if (g > f[0])
                {
                    swap(g, f[0]);
                }
                if ((g > f[1] && g[1] != f[0][1]) || f[0][1] == f[1][1])
                {
                    f[1] = g;
                }
            }
            else
            {
                for (auto [z, d] : f)
                {
                    if (d != c)
                    {
                        ans[i] = std::min(ans[i], std::max(0, y - z));
                    }
                }
            }
        }
        std::reverse(pts.begin(), pts.end());
        for (auto &[x, y, c, i, o] : pts)
        {
            x = INF - x;
            y = INF - y;
            o ^= 1;
        }
    }
    fr(i, 0, n - 1)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
