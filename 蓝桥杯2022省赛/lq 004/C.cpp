#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
ll pre[20];
ll n;
ll ans;
ll count(ll x){ll res = 0; while (x) res += x & 1,x >>= 1; return res;}
void dfs(ll pos,ll sum,ll ant)
{
    if(sum>n) return;
    if(pos==15)
    {
    //    cout<<ant+count(n-sum)<<endl;
        ans = min(ans,ant+count(n-sum));
        return ;
    }

    dfs(pos+1,sum,ant);
    dfs(pos+1,sum+pre[pos],ant+1);
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    pre[1] = 1;
    pre[0] = 1;
    for(ll i=1;i<=14;i++)
    {
        pre[i] = pre[i-1]*i;
    }
 //   cout<<count(13)<<endl;
    while(T--)
    {
        ans  = LLONG_MAX-1;
        cin>>n;
        dfs(0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}