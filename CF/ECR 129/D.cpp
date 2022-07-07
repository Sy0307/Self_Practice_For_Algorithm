#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
constexpr int inf = 1E9;

map<ll,int> mp;
int dfs(ll x,ll limit)
{
    if(x>=limit)
    {
        return 0;
    }
    else if(mp.contains(x))
    {
        return mp[x];
    }
    else 
    {
        int &ans = mp[x] = inf;
        auto s = to_string(x);
        for(auto &now:s)
        {
            int d = now-'0';
            if(d>=2)
            {
                ans = min(ans,1+dfs(x*d,limit));
            }
        }
        return ans;
    }
}
void solve()
{
    ll n,x;
    cin>>n>>x;
    ll limit = 1;
    limit = pow(10,n-1);
    auto ans = dfs(x,limit);
    if(ans == inf)
    {
        cout<<-1<<endl;
    }
    else cout<<ans<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    solve();
}