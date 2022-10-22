#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
#define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)
istream &operator>>(istream &in, vector<int> &v)
{
    for (auto &i : v)
        in >> i;
    return in;
}
ostream &operator<<(ostream &out, vector<int> &v)
{
    for (auto &i : v)
        out << i << " ";
    return out;
}

void solve()
{
    int me = -1, me2 = -1;
    int mo = -1, mo2 = -1;
    int n;
    cin >> n;
    fr(i, 1, n)
    {
        int x;
        cin >> x;
        if (x & 1)
        {
            if (x > me)
            {
                me2 = me;
                me = x;
            }
            else if (x > me2)
            {
                me2 = x;
            }
        }
        else
        {
            if (x > mo)
            {
                mo2 = mo;
                mo = x;
            }
            else if (x > mo2)
            {
                mo2 = x;
            }
        }
    }
    int ans1 = -1;
    if (me != -1 && me2 != -1)
    {
        ans1 = me + me2;
    }
    int ans2 = -1;
    if (mo != -1 && mo2 != -1)
    {
        ans2 = mo + mo2;
    }
    cout << max(ans1, ans2) << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}