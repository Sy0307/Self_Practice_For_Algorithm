#include<bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> a;
void init()
{
    ll ans = 0;
    for(int i=1;i<=50000;i++)
    {
        int now = (i-1)*4;
        ans+=now;
        a.push_back(ans);
        ans +=(now+2);
        a.push_back(ans);
        ans+=(now+4);
        a.push_back(ans);
    }
}
void solve()
{
    int n;
    cin>>n;
    cout<<lower_bound(a.begin(),a.end(),n) - a.begin() +1<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;cin>>T;
    init();
    while(T--)
    {
        solve();
    }
    return 0;
}