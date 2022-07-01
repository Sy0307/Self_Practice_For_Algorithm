#include<bits/stdc++.h>
using namespace std;

using ll = long long ;
void solve()
{
    ll n,m;
    cin>>n>>m;
    ll ans = 0;
    ans = (m*(m+1))/2;
    ans += ((n+2)*m*(n-1))/2;
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}