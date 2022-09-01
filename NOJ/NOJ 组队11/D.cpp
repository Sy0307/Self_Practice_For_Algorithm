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

int n, m, d;
int cnta, cntb;
ll a[maxn], b[maxn];
ll k[maxn], s[maxn];
void solve()
{
    cin >> n >> d >> m;
    fr(i, 1, n)
    {
        int x;
        cin >> x;
        if (x > m)
        {
            a[++cnta] = x;
        }
        else
        {
            b[++cntb] = x;
        }
    }

    sort(a + 1, a + cnta + 1, greater<ll>());
    sort(b + 1, b + cntb + 1);

    for (int i = 1; i <= cnta; i++)
    {
        k[i] = a[i] + k[i - 1];
    }
    for (int i = 1; i <= cntb; i++)
    {
        s[i] = b[i] + s[i - 1];
    }

    ll ans = s[cntb];
    for (int i = 0; i <= cnta; i++)
    {
        if (i * (d + 1) + 1 > n)
            break;
        int need = i * d;
        int leave = cnta - (i + 1);
        need = max(need - leave, 0);
        ll tmp = s[cntb] - s[need] +k[i] +a[i+1];
        ans = max(ans, tmp);
    }
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