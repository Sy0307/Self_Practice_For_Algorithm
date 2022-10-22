#include<bits/stdc++.h>
using namespace std;
const int N = 1002;

int n,m,ans = -INT_MAX;
int sum[N][N] , ll[N],rr[N];
int x,y;
int make(int i,int j,int x,int y)
{
    return sum[i+x-1][j] -sum[i-1][j] - sum[i+x-1][j-y]+sum[i-1][j-y];
}
void h(int n,int m,int x,int y)
{
    for(int i=n-x+1;i;--i)
    {
        if(ll[i]<ll[i+1]) ll[i] = ll[i+1];
        for(int j=y;j<=m;j++)
        {
            int t=  make(i,j,x,y);
            ll[i] = max(t,ll[i]);
        }
    }
}
void s(int n,int m,int x,int y)
{
    for(int i=n-y+1;i;--i)
    {
        rr[i] = max(rr[i],rr[i+1]);
        for(int j=1;j+x<=m+2;j++)
        {
            int t=  make(j,i+y-1,x,y);
            rr[i] = max(t,rr[i]);
        }
    }
}
void finish(int x,int y)
{
    for(int i=1;i<n+2-x;i++)
        for(int j=y;j<=m;j++)
        {
            int t = make(i,j,x,y);
            if (i+x<=n && t+ll[i+x]>ans) ans=t+rr[i+x];
            if (j<m && t+rr[j+1]>ans) ans=t+rr[j+1];
        }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>sum[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j] = sum[i-1][j]+sum[i][j-1] - sum[i-1][j-1];

    for(int i=1;i<=n+1;i++) ll[i] = ans;
    for(int i=1;i<=n+1;i++) rr[i] = ans;
    h(n,m,x,y);h(n,m,y,x);
    s(m,n,x,y);s(m,n,y,x);
    finish(x,y);finish(y,x);


    cout<<ans<<endl;

    return 0;
}