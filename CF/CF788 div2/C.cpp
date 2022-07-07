#include<bits/stdc++.h>
using namespace std;
const int  N = 100010;
int a[100010],b[N],c[N],pos[N];
bool vis[N],st[N];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        vis[i] = st[i]  = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]!=0)
        {
            st[a[i]] = st[b[i]]= 1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        pos[a[i]] = b[i];
    }
    long long ans = 1;
    int mod = 1e9 + 7;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            bool f = 0;
            int cnt = 0;
            for(int j = i;!vis[j];j = pos[j])
            {
                vis[j] = 1;
                cnt++;
                f |=st[j];
            }
            if(!f && cnt!=1) ans = ans*2 %mod;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}