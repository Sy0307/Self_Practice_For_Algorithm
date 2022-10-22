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
int pos[maxn] , p[maxn];
void solve()
{
    cin >> n;
    fr(i, 0, n)
    {
        pos[i] = 0;
    }
    fr(i, 1, n)
    {
        cin >> p[i];
        pos[p[i]] = i;
    }
    ll ans = 0;
    int l = pos[0], r = pos[0];
    fr(x, 1, n)
    {
        if (x != n && l <= pos[x] && pos[x] <= r)
        {
            continue;
        }
        int maxlen = 2 * x;
        if (maxlen >= (r - l + 1))
        {
            if (pos[x] > r)
            {
                fr(i, r, pos[x] - 1)
                {
                    int j = max(1, i - maxlen + 1);
                    ans += max(0, l - j + 1);
                }
            }
            else
            {
                fr(i, pos[x] + 1, l)
                {
                    int j = min(n, maxlen + i - 1);
                    ans += max(0, j - r + 1);
                }
            }
        }
        l = min(l, pos[x]);
        r = max(r, pos[x]);
    }
    cout << ans << endl;
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