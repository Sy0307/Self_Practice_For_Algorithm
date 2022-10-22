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

int a[maxn];
map<int, int> mp;
void solve()
{
    int n;
    mp.clear();
    cin >> n;
    fr(i, 1, n)
    {
        cin >> a[i];
        int now = a[i];
        mp[now] = max(mp[now], i);
    }
    int ans = -1;
    fr(i, 1, 1000)
    {
        fr(j, 1, 1000)
        {
            if (mp[i] && mp[j])
            {
                if (gcd(i, j) == 1)
                {
                    ans = max(ans, mp[i] + mp[j]);
                }
            }
        }
    }

    cout << ans << endl;
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