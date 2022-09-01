
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    using ll = long long ;
    int n;
    cin>>n;
    ll ans  = 0;
    for(int i=0;i<n;i++)
    {
        ll x;cin>>x;
        ans|=x;
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}