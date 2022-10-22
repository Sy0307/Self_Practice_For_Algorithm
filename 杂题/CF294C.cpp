#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int mod = 1000000007;
const int N = 1000005;
int n, m;
LL pos[N], infac[N], fac[N];

LL qmi(LL a, LL b, LL p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}
void init()
{
    fac[0] = 1, infac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = (LL)fac[i - 1] * i % mod;
    infac[N - 1] = qmi(fac[N - 1], mod - 2, mod);
    for (int i = N - 2; i; i--)
        infac[i] = (LL)infac[i + 1] * (i + 1) % mod;
}
LL C(int a, int b) { return (LL)fac[a] * infac[b] % mod * infac[a - b] % mod; }

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //    DEBUG();

    init();
    cin >> n >> m;
    LL ans = fac[n - m];
    for (int i = 1; i <= m; i++)
        cin >> pos[i];
    pos[m + 1] = n + 1;
    sort(pos + 1, pos + m + 1);
    for (int i = 1; i <= m + 1; i++)
    {
        if (pos[i] - pos[i - 1] - 1 > 0)
        {
            int li = pos[i] - pos[i - 1] - 1;
            if (i > 1 && i < m + 1)
                ans = ans * qmi(2, li - 1, mod) % mod;
            ans = ans * infac[li] % mod;
        }
    }

    cout << ans << endl;
    return 0;
}