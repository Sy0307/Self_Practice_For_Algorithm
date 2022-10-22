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

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n), b(a), c(a);
    fr(i, 1, n)
    {
        cin >> a[i - 1];
    }
    fr(i, 1, n)
    {
        cin >> b[i - 1];
    }
    fr(i, 1, n)
    {
        c[i - 1] = -a[i - 1] + b[i - 1];
    }
    sort(c.begin(), c.end());
    ll ans = 0;
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (c[l] + c[r] >= 0)
        {
            l++;
            r--;
            ans++;
        }
        else
        {
            l++;
        }
    }
    cout << ans << endl;
}

int main()
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