#include <algorithm>
#include <bits/stdc++.h>
#include <random>
#define sf(T) sizeof(T)
#define il inline
#define con const
#define cer constexpr
using namespace std;
using sint = size_t;
using uint = unsigned int;
using ll = long long;
using ul = unsigned long long;
template<class T>
using Vec = vector<T>;
template<class T>
using Stk = stack<T>;
using Str = string;
cer ul ULMAX = UINT64_MAX;
cer ul ULINF = 0x3f3f3f3f3f3f3f3f;
cer uint UMAX = UINT32_MAX;
cer uint UINF = 0x3f3f3f3f;
con char *ANS[2] = {"NO", "YES"};
int (*con gc)() = &getchar;

cer ul MOD = 998244353;
cer uint MAX = 2e6;
cer uint MAXN = 10;
cer uint MAXV = 4e2;

uint n, q, seed;
uint dp[MAXN][MAXV][MAXV];

il uint check(uint l, uint r, uint v) {
    uint ans = 0;
    for(uint i = 0; i < n; ++i)
        ans += dp[i][l][r] <= v;
    return ans;
}

il void solve() {
    cin >> seed;
    mt19937 rng(seed);
    uniform_int_distribution<> u(1, 400);
    uint lans = 0; ul ans = 0, p = 1;
    auto ip = [&]() { return (u(rng) ^ lans) % 400; };
    for(uint i = 0; i < q; ++i) {
        uint l = ip();
        uint r = ip();
        uint v = ip();
        lans = check(l, r, v);
        ans += ul(lans) * p; p *= seed;
        ans %= MOD; p %= MOD;
    }
    cout << ans;
}

il void pre() {
    cin >> n >> q;
    memset(dp, 0x3f, sf(dp));
    for(uint i = 0, ip, l, r, v; i < n; ++i) {
        for(cin >> ip, ++ip; --ip;) {
            cin >> l >> r >> v; --l; --r;
            dp[i][l][r] = min(dp[i][l][r], --v);
        }
        for(uint j = 1; j < 400; ++j) {
            dp[i][0][j] = min(dp[i][0][j], dp[i][0][j - 1]);
            dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][0]);
        }
        for(uint j = 1; j < 400; ++j)
            for(uint k = 1; k < 400; ++k) {
                v = min(dp[i][j - 1][k], dp[i][j][k - 1]);
                dp[i][j][k] = min(dp[i][j][k], v);
            }
    }
}

// il void test() {}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // test();
    pre(); solve();
    return 0;
}