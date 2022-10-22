#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
ll mod = 1000000007;
set<int> vis;
ll dp[200010];
ll a[200010];
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        ll x = a[i];
        bool f = 1;
        while(x)
        {
            if(vis.count(x)) 
            {
                f=  0;
                break;
            }
            if(x&1) x>>=1;
            else if(x&2) break;
            else x>>=2;
        }
        if(f) vis.insert(a[i]);
    }
    for(auto &it:vis) dp[(int)floor(log2(it))]++;
    ll ans = 0;
    for(int i=0;i<k;i++)
    {
        if(i>=1) dp[i] = (dp[i]+dp[i-1])%mod;
        if(i>=2) dp[i] = (dp[i]+dp[i-2])%mod;
        ans = (ans+dp[i])%mod;
    }
    cout<<ans<<endl;
    return 0;

}