#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

int fact[maxn], inv[maxn];
void init(int n = 100000)
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (ll)i * fact[i - 1] % mod;
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = mod - (ll)(mod / i) * inv[mod % i] % mod;
    inv[0] = 1;
    for (int i = 1; i <= n; i++)
        inv[i] = (ll)inv[i - 1] * inv[i] % mod;
}
ll cal(int n, int m)
{
    return (ll)fact[n] * inv[m] % mod * inv[n - m] % mod;
}
void solve()
{
    init();
    int n;
    cin>>n;
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans = (ans+cal(n,i)*cal(n-1,i-1)%mod)%mod;
    }
    
    ans = (ans*2%mod - n +mod)%mod;
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}