#include <bits/stdc++.h>
#define sf(T) sizeof(T)
#define inl inline
#define stc static
#define con const
#define cer constexpr
#define ret return
#define whi(c) while (c)
using namespace std;
using is = int;
using il = long long;
using us = unsigned int;
using ul = unsigned long long;
using fs = float;
using fl = double;
#define ix __int128
using fx = long double;
cer ul ULINF = UINT64_MAX, LINF = 0x3f3f3f3f3f3f3f3f;
cer us USINF = UINT32_MAX, SINF = 0x3f3f3f3f;
con string ANS[2] = {"NO", "YES"}; // 可自定义二元答案
extern con ul MOD;
extern con us MAX;
template <class T>
inl void mem(T *arr, us b, us n) { memset(arr, b, n * sf(T)); }
// <- -- --- ----header end---- --- -- ->

cer ul MOD = 998244353;
cer us MAX = 5e5;

ul C[MAX];
us n;

cer us MAXM = MAX - 1;
cer us MAXE = MAXM << 1;
struct Graph
{
    us hd[MAX], du[MAX];
    us tar[MAXE], nx[MAXE], it;
    using puu = pair<us, us>;
    inl void mem(us n)
    {
        ::mem(hd, it = USINF, n);
        ::mem(du, 0, n);
    }
    inl void add(us u, us v)
    {
        nx[++it] = hd[u];
        tar[it] = v;
        hd[u] = it;
        ++du[v];
    }
    inl void solve()
    {
        ul dp[2][4][3] = {0}, ans = 0;
        ul(*c)[3] = dp[0], (*p)[3] = dp[1];
        for (us u = 0, v; u < n; ++u)
        {
            memset(c, 0, sf(dp[0]));
            for (us e = hd[u]; ~e; e = nx[e])
            {
                swap(p, c);
                p[0][0] = 1;
                memset(c, 0, sf(dp[0]));
                v = tar[e];
                // head
                for (us i = 0; i < 3; ++i)
                {
                    (c[1][i] += p[0][i]) %= MOD;
                    (c[3][i] += p[2][i]) %= MOD;
                }
                // arms
                for (us i = 0; i < 4; ++i)
                {
                    (c[i][1] += p[i][0] * (du[v] - 1)) %= MOD;
                    (c[i][2] += p[i][1] * (du[v] - 1)) %= MOD;
                }
                // body
                for (us i = 0; i < 3; ++i)
                {
                    (c[2][i] += p[0][i] * C[du[v] - 1]) %= MOD;
                    (c[3][i] += p[1][i] * C[du[v] - 1]) %= MOD;
                }
                (ans += c[3][2]) %= MOD;
            }
        }
        cout << ans << endl;
        // TODO: base.h!!!!!!!!!
    }
} g;

inl void pre()
{
    cin >> n;
    g.mem(n);
    for (us i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        --u;
        --v;
        g.add(u, v);
        g.add(v, u);
    }
}

inl void spre()
{
    for (us i = 2; i < MAX; ++i)
        C[i] = ((ul(i ^ 1) >> 1) * (i - 1)) % MOD;
}

is main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // us _t; scanf("%d", &_t); ++_t;
    spre();
    us _t;
    cin >> _t;
    ++_t;
    whi(--_t)
    {
        pre();
        g.solve();
    }
    ret 0;
}
