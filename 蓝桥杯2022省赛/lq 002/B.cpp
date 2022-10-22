#include<bits/stdc++.h>
using namespace std;


int t[1010],a[1010],w[1010];
int f[1010][1010];
int main()
{
    ios::sync_with_stdio(false);
    int tt,aa;
    cin>>tt>>aa;
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i]>>a[i]>>w[i];
    }
    memset(f,0x3f,sizeof(f));
    f[0][0] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j = 100;j>=t[i];j--)
            for(int k = 100;k>=a[i];k--)
            {
                f[j][k] = min(f[j][k],f[j-t[i]][k-a[i]]+w[i]);
            }
    }
    int ans = 9999999;
    for(int i=tt;i<=100;i++)
        for(int j=aa;j<=100;j++)
            ans = min(ans,f[i][j]);
    cout<<ans<<endl;
    return 0;
}