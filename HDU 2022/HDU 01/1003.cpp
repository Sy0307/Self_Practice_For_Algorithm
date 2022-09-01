#include <bits/stdc++.h>
#define sf(T) sizeof(T)
#define il inline
#define con const
#define def typedef
using namespace std;
def size_t sint;
def unsigned int uint;
def long long ll;
def unsigned long long ul;
con ul ULMAX = -1ull;
con uint UMAX = -1u;
con uint UINF = 0x3f3f3f3f;
con char *ANS[2] = {"NO", "YES"};
int (*con gc)() = &getchar;
con ul MOD = 1e9+7;
// cer ull MOD = 998244353;

con uint MAX = 1024;

sint n, m;
//      背包容量，xor sum
bool dp[MAX+1][MAX];

il uint mbit(uint x) {
    while(x!=(x&-x)) x ^= (x&-x);
    return x<<1;
}

il void solve() {
    dp[0][0] = 1; uint mx = 0;
    for(uint v, w; --n; ) {
        cin >> w >> v; mx = max(mx, mbit(v));
        for(sint i=m; i>=w; --i)
            for(uint s=0; s<mx; ++s)
                if(dp[i-w][s^v]) dp[i][s] = 1;
    }
    uint ans = 0;
    for(uint i=1; i<mx; ++i)
        if(dp[m][i]) ans = i;
    cout << ans << endl;
}

il void pre() {
    cin >> n >> m; ++n;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            dp[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // pre(); solve();
    // uint _t; scanf("%d", &_t); ++_t;
    uint _t; cin >> _t; ++_t;
    while(--_t) { pre(); solve(); }
    return 0;
}