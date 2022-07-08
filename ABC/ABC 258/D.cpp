#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    using ll = long long;
    ll n, x;
    cin >> n >> x;
    ll a[n], b[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cin >> b[i];
    }
    ll ans = LLONG_MAX;
    ll t = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i > x)
            break;
        t += a[i] + b[i];
        ans = min(ans,t+(ll)(x-i)*(b[i]));
    }
    cout<<ans<<endl;
    return 0;
}