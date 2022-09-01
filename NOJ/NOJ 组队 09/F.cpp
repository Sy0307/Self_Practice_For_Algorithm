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

ull change(ll x)
{
    ull res = 0;
    ull cnt = 1;
    while (x)
    {
        res += (x&1)*cnt;
        x/=10;
        cnt*=2;
    }
    return res;
}
void solve()
{
    unordered_map<ull, ull> mp;
    int q;
    cin >> q;
    while (q--)
    {
     //   cout<<1<<endl;
        char type;
        ull x;
        cin >> type >> x;
        if (type == '+')
        {
            mp[change(x)]++;
        }
        else if (type == '-')
        {
            mp[change(x)]--;
        }
        else
        {
            cout<<mp[change(x)]<<endl;
        }
    }
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