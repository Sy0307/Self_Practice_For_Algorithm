#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 262144 + 10;
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
int a[maxn], c[maxn];

bool f = 0;
ll ans = 0;
void merge(int l, int r)
{
    if (f == 1)
        return;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    merge(l, mid);
    merge(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    ll cnt = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = a[j++];
            cnt++;
        }
    }
    cnt = min(1LL,cnt);
    ans += cnt;
    while (i <= mid)
    {
        c[k++] = a[i++];
    }
    while (j <= r)
    {
        c[k++] = a[j++];
    }
    for (int i = l; i <= r; i++)
        a[i] = c[i];
    if (r - l != a[r] - a[l])
    {
        f = 1;
    }
}
void solve()
{
    int n;
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        c[i] = 0;
    }
    f = 0;
    fr(i, 1, n)
    {
        cin >> a[i];
    }
    merge(1, n);
    if (f == 1)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << ans << endl;
    }
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