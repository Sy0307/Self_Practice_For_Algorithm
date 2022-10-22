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
int a[maxn];
int n;
ll ans;
bool check(ll piece)
{
    ll maxlen = 0;
    ll now = 0;
    for (int i = 1; i <= n; i++)
    {
        now += a[i];
        maxlen++;
        if (now > piece)
        {
            return false;
        }
        else if(now==piece)
        {
            now=0;
            ans = max(ans, maxlen);
            maxlen = 0;
        }
    }
    return true;
}
void solve()
{
    cin >> n;
    ans = n;
    ll tot = 0;
    ll res = n;
    fr(i, 1, n)
    {
        cin >> a[i];
        tot += a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        if (tot % i != 0)
            continue;
        int val = tot / i;
        ans = 0;
        if (check(val))
        {
            if (ans < res)
            {
                res = ans;
            }
        }
    }
    cout << res << endl;
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