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
#define endl '\n'
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
const int N = 2e5 + 10, INF = 0x3f3f3f3f;
const double eps = 1e-5;

map<ll, ll> mp[11];
int n, k;
ll a[N];
int i, j;
ll cnt[N];
ll ans;

void solve()
{
    cin >> n >> k;
    fr(i, 1, n)
    {
        cin >> a[i];
        ll temp = a[i];
        if (!temp)
            cnt[i] = 1;
        else
        {
            while (temp)
            {
                cnt[i]++;
                temp /= 10;
            }
        }
        mp[cnt[i]][a[i] % k]++;
    }

    fr(i, 1, n)
    {
        ll x = a[i];

        fr(j, 1, 10)
        {
            x = x * 10 % k;
            if (mp[j].count((k - x) % k))
            {
                ans += mp[j][(k - x) % k];
                if (cnt[i] == j && a[i] % k == (k - x) % k)
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
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}