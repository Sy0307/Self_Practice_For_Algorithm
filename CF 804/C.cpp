#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int> pos(n), a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int L = INT_MAX / 2;
    int R = INT_MIN / 2;
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
    //    cout<<i<<endl;
        auto tmp = pos[i];
        if (L <= tmp && R >= tmp)
        {
            ans *= (R - L + 1 - i);
            ans %= mod;
        }
        if (tmp < L)
            L = tmp;
        if (tmp > R)
            R = tmp;
        //    cout<<1<<endl;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while (T--)
    {
        solve();
    }
}