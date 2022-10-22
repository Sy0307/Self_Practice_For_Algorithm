#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e6 + 10;
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
int a[maxn];
int n,k;
ll sum[maxn];
void solve()
{
    cin >> n >> k;
    sum[0] = 0;
    fr(i, 1, n)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int l = k - 1, r = k + 1, lmx = 0, rmx = 0;
    int lnow = 0, rnow = 0;
    while (l && r <= n)
    {
        if (a[k] + lmx + rnow + a[r] >= 0)
        {
            rnow = rnow + a[r];
            r++;
            rmx = max(rmx, rnow);
            continue;
        }
        if (a[k] + rmx + lnow + a[l] >= 0)
        {
            lnow = lnow + a[l];
            l--;
            lmx = max(lmx, lnow);
            continue;
        }
        break;
    }
    if (l == 0 || r == n + 1)
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