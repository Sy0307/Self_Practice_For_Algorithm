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
int l, r, t;
int n;
void solve()
{
    cin >> l >> r >> t;
    cin >> n;
    int ans = 0;
    int kk = 1000000012100;
    fr(i, 1, n)
    {
        int x;
        cin >> x;
        if (x + t <= r)
        {
            if (max(x - 1, l) + t <= r && l - (x - 1) < kk)
            {
                kk = l - (x - 1);
                ans = min(x - 1, l);
            }
            l = max(l, x) + t;
        }
    }
    if (l + t <= r)
        ans = l;
    cout << ans << endl;
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