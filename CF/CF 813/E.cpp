#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 5e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

vector<int> fac[maxn];
void pre()
{
    fr(i, 1, maxn - 1)
    {
        for (int j = 2 * i; j < maxn; j += i)
        {
            fac[j].push_back(i);
        }
    }
}
void solve()
{
    int l, r;
    cin >> l >> r;
    int len = r - l + 1;
    ll ans = 1LL * len * (len - 1) * (len - 2) / 6;
    fr(k, l + 2, r)
    {
        for (auto x : fac[2 * k])
        {
            if (x < l)
                continue;
            if (k % x && x * 2 <= k)
                continue;
            if (x >= k)
                break;
            for (auto y : fac[2 * k])
            {
                if (y < l)
                    continue;
                if (y >= x)
                    break;
                if (k % x || k % y)
                    ans -= (2 * k < x + y + k);
                else
                    ans--;
            }
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
    pre();
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}