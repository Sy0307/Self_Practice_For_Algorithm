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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
istream &operator>>(istream &in, vector<ll> &v)
{
    for (auto &i : v)
        in >> i;
    return in;
}
ostream &operator<<(ostream &out, vector<ll> &v)
{
    for (auto &i : v)
        out << i << " ";
    return out;
}

int n;
ll merge_sort(vector<ll> &pre, int l, int r)
{
    if (l >= r)
    {
        return 0;
    }

    vector<ll> tmp(r - l + 1, 0);
    int mid = (l + r) >> 1;
    ll res = merge_sort(pre, l, mid) +
             merge_sort(pre, mid + 1, r);

    int k = 0, i = l, j = mid + 1;

    while (i <= mid && j <= r)
    {
        if (pre[i] <= pre[j])
        {
            tmp[k++] = pre[i++];
        }
        else
        {
            res += mid - i + 1;
            tmp[k++] = pre[j++];
        }
    }
    while (i <= mid)
        tmp[k++] = pre[i++];
    while (j <= r)
        tmp[k++] = pre[j++];

    fr(i, l, r)
    {
        pre[i] = tmp[i - l];
    }
    return res;
}
void solve()
{
    cin >> n;
    vector<ll> a(n+1), pre(n+1, 0);
    fr(i, 1, n)
    {
        cin >> a[i - 1];
    }
    // cout << a << endl;

    pre[0] = a[0];
    fr(i, 1, n - 1)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    ll t = pre[n - 1];

    ll ans = merge_sort(pre, 0, n - 1);
    // fr(i, 1, n)
    // {
    //     cout << pre[i - 1] << endl;
    // }
    if (pre[0] < 0 || pre[n - 1] != t)
    {
        cout << -1 << endl;
    }
    else
        cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}