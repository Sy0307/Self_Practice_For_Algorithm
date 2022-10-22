#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e6 + 10;
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

ll mp[maxn];
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    fr(i, a, b)
    {
        mp[i + b]++;
        mp[i + c + 1]--;
    }
    fr(i, 1, maxn-1)
    {
        mp[i] += mp[i - 1];
    }
    for (int i = maxn-1; i >= 0; i--)
    {
        mp[i] += mp[i + 1];
    }
    ll ans = 0 ;
    fr(i,c,d)
    {
        ans+=mp[i+1];
    }
    cout<<ans<<endl;
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