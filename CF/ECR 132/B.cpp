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

ll h[maxn];
ll pre[maxn];
ll suf[maxn];
void solve()
{
    int n, q;
    cin >> n >> q;
    fr(i, 1, n)
    {
        cin >> h[i];
    }
    fr(i, 2, n)
    {
        int now = 0;
        if (h[i] < h[i - 1])
        {
            now = h[i - 1] - h[i];
        }
        pre[i] = pre[i - 1] + now;
    }
    ford(i, n - 1, 1)
    {
        int now = 0;
        if (h[i] < h[i + 1])
        {
            now = h[i + 1] - h[i];
        }
        suf[i] = suf[i + 1] + now;
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (l > r)
        {
            cout << suf[r] - suf[l] << endl;
        }
        else
            cout << pre[r] - pre[l] << endl;
    }
}
int main()
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