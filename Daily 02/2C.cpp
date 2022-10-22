#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    vector<ll> pre(n + 1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    pre[0] = 0;
    for(int i=1;i<=n;i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    ll ans = LLONG_MAX;
    for(int i=1;i<=n;i++)
    {
        ll t = 0;
        if(pre[i] + (n-i)*a[1]<=k) t = 0;
        else t = ceil((pre[i] + (n-i)*a[1] - k) * 1.000000/(n-i+1));
        ans = min(ans, n -i + t);
    }
    cout<<ans<<endl;
    
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