#include <bits/stdc++.h>
#define sf(T) sizeof(T)
#define il inline
#define con const
using namespace std;
using sint = size_t;
using uint = unsigned int;
using ll = long long;
using ul = unsigned long long;
template <class T>
using Vec = vector<T>;
template <class T>
using Stk = stack<T>;
using Str = string;
con ul ULMAX = UINT64_MAX;
con uint UMAX = UINT32_MAX;
con uint UINF = 0x3f3f3f3f;
con char *ANS[2] = {"NO", "YES"};
int (*con gc)() = &getchar;
con ul MOD = 1e9 + 7;
// con ull MOD = 998244353;

con uint MAX = 2e5;

sint n;
uint inp;

il void query(sint k, sint j = 2, sint i = 1)
{
    cout << "? " << i << ' ' << j << ' ' << k << endl;
    cout.flush();
    cin >> inp;
}

il void ans(sint x, sint y)
{
    cout << "! " << x << ' ' << y << endl;
    cout.flush();
}

il void solve()
{
    sint x = 3, y = 0;
    query(3);
    bool upt = 0;
    uint mdx = inp, mdy = 0;
    for (sint i = 4; i <= n; ++i)
    {
        if (query(i), inp != mdx)
            upt = 1;
        if (inp >= mdx)
        {
            x = i;
            mdx = inp;
        }
    }
    if (upt)
    {
        mdy = mdx;
        bool fg = upt = 0;
        for (sint i = 3; i <= n; ++i)
        {
            if (i == x)
                continue;
            if (query(x, i), inp != mdy)
                upt = 1;
            if (inp >= mdy)
            {
                fg = 1;
                y = i;
                mdy = inp;
            }
        }
        if (!upt)
            ans(1, x);
        else if (fg)
            ans(x, y);
        else
            ans(2, x);
    }
    else
        ans(1, 2);
}

il void pre() { cin >> n; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    uint _t;
    cin >> _t;
    ++_t;
    while (--_t)
    {
        pre();
        solve();
    }
    return 0;
}