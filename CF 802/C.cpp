#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// 1 = d[1] -1 d[i+1] ++
// 2 = d[i+1] --;
// 3 = d[1]++;
void solve()
{
    int n;
    cin >> n;
    using ll = long long ;
    vector<ll> diff(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i == 1)
        {
            diff[i] = a[i];
        }
        else
            diff[i] = a[i] - a[i - 1];
    }
    ll ans = 0;
    for(int i=2;i<=n;i++)
    {
        if(diff[i]>0)
        {
            ans+=diff[i];
        }
        else
        {
            ans-=diff[i];
            diff[1]+=diff[i];
        }
    }
    cout<<ans+abs(diff[1])<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}