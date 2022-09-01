#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

ll x = 0;
bitset<100> bs;
int ans[100];
void solve()
{
    int n;
    ll m;
    cin >> n >> m;
    m--;
    while (x < n)
    {
        if ((1LL << x) & m)
        {
            bs[x] = 1;
        }
        else
            bs[x] = 0;
        x++;
    }
    int s1 = 1, s2 = n;
    int now = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (bs[i] == 1)
        {
            ans[s2] = now;
            s2--;
        }
        else
        {
            ans[s1] = now;
            s1++;
        }
        now++;
    }
    ans[s1] = n;
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}