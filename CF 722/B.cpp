#include <bits/stdc++.h>
#define sf(T) sizeof(T)
#define il inline
#define con const
using namespace std;
using sint = size_t;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T>
using Vec = vector<T>;
template<class T>
using Stk = stack<T>;
using Str = string;
con uint UMAX = UINT32_MAX;
con uint UINF = 0x3f3f3f3f;
con char *ANS[2] = {"NO", "YES"};
int (*con gc)() = &getchar;
con ull MOD = 1e9+7;
// con ull MOD = 998244353;

con uint MAX = 2e5;

con uint MAXM = 1e5;
con uint MAXE = MAXM<<1;
struct EL{ sint v; /*, uint w;*/ EL *net; }
pool[MAXE], *head[MAX], *iter=pool-1;
using pus = pair<uint, sint>;

sint n;
uint inp[MAX+1];

il void solve() {
    sint ans = 0;
    for(sint i=1; i+1<n; ++i)
        if(inp[i-1]<inp[i]&&inp[i]>inp[i+1]) {
            ++ans; ++i; 
            if(i+1<n) inp[i] = max(inp[i-1], inp[i+1]);
            else inp[i] = inp[i-1];
        }
    cout << ans << endl;
    for(sint i=0; i<n; ++i)
        cout << inp[i] << " \n"[i+1==n];
}

il void pre() {
    cin >> n;
    for(sint i=0; i<n; ++i)
        cin >> inp[i];
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