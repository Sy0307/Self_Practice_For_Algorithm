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

void solve()
{
    int n;
    cin >> n;
    int now = 9;
    int idx = 0;
    ll ans = 0;
    while (n)
    {
        if (n > now)
        {
            n -= now;
            ans += now * pow(10, idx);
            now--;
        }
        else
        {
            ans+=n * pow(10, idx);
            cout<<ans<<endl;
            return;
        }
        idx++;
    }
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