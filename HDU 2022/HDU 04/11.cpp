#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> B;
void insert(ll x)
{
    for (auto b : B)
        x = min(x, b ^ x);
    for (auto &b : B)
        b = min(b, b ^ x);
    if (x)
        B.push_back(x);
}
void solve()
{
    B.clear();
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    ll ans = 0;
    for(auto &now:B)
    {
        ans = max(ans, ans^now);
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}