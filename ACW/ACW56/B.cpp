#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2000010;
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
int n, k;
int pre[maxn], f[maxn];

void init()
{
    fr(i, 1, maxn - 1)
    {
        pre[i]+=pre[i - 1];
    }
}
int get(int l, int r)
{
    return pre[r] - pre[l];
}

void solve()
{
    cin >> n >> k;
    vector<int> a(n);
    fr(i, 1, n)
    {
        int x;
        cin >> x;
        a[i - 1] = x;
        pre[x]++;
    }
    init();
    int cnt = 0;
    fr(i, 1, n)
    {
        int now = a[i - 1];
        if (get(now, now + k) > 0)
        {
            cnt++;
        }
    }
    cout << n - cnt << endl;
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