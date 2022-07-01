#include<bits/stdc++.h>
using namespace std;

int mp[301][301];
int dis[301][301];
int edge[302];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j] = 9999999999;
    int ans = 0;
    for(int k=1;k<=m;k++)
    {
        int i,j;
        cin>>i>>j;
        cin>>mp[i][j];
        dis[i][j] = mp[i][j];
        edge[i]++;edge[j]++;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(mp[i][j]>=dis[i][j]&&edge[i]>=2)
            {
                cout<<i<<" "<<j<<endl;
                ans++;
            }
        }
    ans = min(ans,m-n+1);
    cout<<ans<<endl;
    return 0;


}