#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
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

#define int long long 
ll n, a, r, m;
ll b[maxn];
ll check(int mid)
{
    ll ans = 0;
    ll up = 0, down = 0;
    fr(i, 1, n)
    {
        if (b[i] < mid)
            up += mid - b[i];
        else if (b[i] > mid)
        {
            down += b[i] - mid;
        }
    }
    ans = up * a + down * r;
    ll num = min(up, down);
    if (a + r > m)
    {
        ans += m * num - (a + r) * num;
    }
    return ans;
}
void solve()
{
    ll ans = 1e18;
    // cout<<ans<<endl;
    cin >> n >> a >> r >> m;
    fr(i, 1, n)
    {
        cin >> b[i];
    }
    int l = 0, r = 1e9;
    while (l + 4 <= r)
    {
        int mid = (r - l + 1) / 3;
        int mid1 = l + mid, mid2 = r - mid;
        ll sum1 = check(mid1), sum2 = check(mid2);
        if (sum1 > sum2)
        {
            l = mid1;
        }
        else
            r = mid2;
    }
    for (int i = l; i <= r; i++)
    {
        ans = min(ans, check(i));
    }
    cout << ans << endl;
    return;
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