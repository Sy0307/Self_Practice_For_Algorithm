#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1010;
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
int a[maxn][maxn];
int make(int b[], int k)
{
    ll ans = 0;
    ll t = 1;
    for (int i = 1; i <= k; i++)
    {
        ans += t * b[i];
        t *= 3;
    }
    vector<int> a;
    return ans;
}
void solve()
{
    cin >> n >> k;
    fr(i, 1, n)
    {
        fr(j, 1, k)
        {
            cin >> a[i][j];
        }
    }
    set<ll> s;
    fr(i, 1, n)
    {
        s.insert(make(a[i], k));
    }
    int ans = 0;
    int c[maxn] = {0};
    fr(i, 1, n)
    {
        int cnt = 0;
        fr(j, 1, n)
        {
            if (i == j)
                continue;
            fr(t, 1, k)
            {
                if (a[i][t] == a[j][t])
                    c[t] = a[j][t];
                else
                    c[t] = 3 - a[j][t] - a[i][t];
            }
            if (s.count(make(c, k)))
                cnt++;
        }
        cnt /= 2;
        ans += (cnt * (cnt - 1)) / 2;
    }
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