#include <bits/stdc++.h>
#define sf(T) sizeof(T)
#define il inline
#define con const
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
con ul ULMAX = UINT64_MAX;
con uint UMAX = UINT32_MAX;
con uint UINF = 0x3f3f3f3f;
con char *ANS[2] = {"NO", "YES"};
int (*con gc)() = &getchar;
con ul MOD = 1e9+7;
// cer ull MOD = 998244353;

con uint MAX = 2e6;

sint cnt;
bool npri[MAX+1];
ul pri[MAX>>1];

ul p, q, e;

bool is_pri(ul num) {
    if(num<=MAX) return !npri[num];
    con ul lit = num>>1;
    for(sint i=0; i<cnt&&pri[i]<=lit; ++i)
        if(!(num%pri[i])) return false;
    return true;
}

sint ct;
ul M[MAX>>1];

il void solve() {
    ul m = p*q-1;
    if(is_pri(m)) {
        cout << ((q*e)%m) << endl;
        return;
    }
    con ul lit = m>>1, base = max(p, q);
    for(sint i=0; i<cnt&&pri[i]<=lit; ++i) {
        if(!(m%pri[i])) {
            con ul l = pri[i], r = m / l;
            if(l>base) M[ct++] = l;
            if(is_pri(r)&&r>base) M[ct++] = r;
        }
    }
    if(ct==0) {
        cout << "shuanQ" << endl;
        return;
    }
    ul ans = (q*e)%M[0];
    while(--ct)
        if(((q*e)%M[ct])!=ans) {
            cout << "shuanQ" << endl;
            return;
        }
    cout << ans << endl;
}

il void pre() {
    ct = 0;
    cin >> p >> q >> e;
}

il void spre() {
    pri[0] = 2;
    for(sint i=4; i<=MAX; i+=2)
        npri[i] = 1;
    for(sint i=3; i<MAX; ++i)
        if(!npri[i]) {
            pri[++cnt] = i;
            for(sint j=i+i; j<MAX; j+=i)
                npri[j] = 1;
        }
    ++cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    spre();
    uint _t; cin >> _t; ++_t;
    while(--_t) { pre(); solve(); }
    return 0;
}