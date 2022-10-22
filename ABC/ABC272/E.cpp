#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 5e5 + 10;
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

vector<int> v[maxn];
int n, m;
int a[maxn];
void solve()
{
    cin >> n >> m;
    fr(i, 1, n)
    {
        cin >> a[i];
        if (a[i] > n)
            continue;
        int l = a[i] > 0 ? 1 : (i - a[i] - 1) / i;
        int r = min(m, (n - a[i]) / i);
        fr(j, l, r)
        {
            v[j].push_back(a[j] + j * i);
        }
    }
    fr(i, 1, m)
    {
        int sz = v[i].size();
        vector<bool> st(sz + 1);
        for (auto j : v[i])
        {
            if (j <= sz)
                st[j] = 1;
        }
        int ans =  0;
        while(st[ans])
            ans++;
        cout<<ans<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}