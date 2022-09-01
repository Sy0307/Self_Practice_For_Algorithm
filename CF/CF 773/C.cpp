#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll ans = 0;
    ll n,x;
    cin>>n;
    cin>>x;
    map<ll,int> mp;
    for(int i=1;i<=n;i++)
    {
        ll tmp;cin>>tmp;
        mp[tmp]++;
    }
    for(auto &now:mp)
    {
        if(now.second==0) continue;
        ll tmp = now.first*x;
        if(mp[tmp])
        {
            if(mp[tmp]>=now.second)
            {
                mp[tmp]-=now.second;
            }
            else
            {
                ans+=now.second-mp[tmp];
                mp.erase(mp.find(tmp));
            }
        }
        else ans+=now.second;
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