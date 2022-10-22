#include<bits/stdc++.h>
using namespace std;
const int N = 1000+2;
int n;
int mp[N][N];
int dp[N][N][2];
int f2[N][N];
int f5[N][N];
int make2(int x)
{
    int ans = 0;
    while(x)
    {
        if(x%2==0) ans++;
        x>>=1;
    }
    return ans;
}
int make5(int x)
{
    int ans = 0;
    while(x)
    {
        if(x%5==0) ans++;
        x/=5;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    bool flag = 0;
    int pos =-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>mp[i][j];
            if(mp[i][j]==0) flag=1,pos = i;
            f2[i][j] = make2(mp[i][j]);
            f5[i][j] = make5(mp[i][j]);
        }
    }
    dp[1][1][0] = f2[1][1];
    dp[1][1][1] = f5[1][1];

    for(int i=2;i<=n;i++)
    {
        dp[i][1][1] +=dp[i-1][1][1];
        dp[i][1][0] +=dp[i-1][1][0];

        dp[1][i][1] +=dp[1][i-1][1]; 
        dp[1][i][0] +=dp[1][i-1][0];
    }

    for(int i=2;i<=n;i++)
        for(int j=2;j<=n;j++)
        {
            dp[i][j][0] = min(dp[i-1][j][0],dp[i][j-1][0]);
            dp[i][j][1] = min(dp[i-1][j][1],dp[i][j-1][1]);
        }

    int res = min(dp[n][n][1],dp[n][n][0]);
    if(flag&&res>0)
    {
        cout<<1<<endl;
        for(int i=1;i<=pos;i++) cout<<"D";
        for(int i=1;i<=n-1;i++) cout<<"R";
        for(int i=pos;i<=n-1;i++) cout<<"D";
        return 0;
    }

    int k = 0;
    if(dp[n][n][0]>dp[n][n][1]) k =1;
    int x = n,y=n;
    string ans="";
    while(1)
    {
        if(dp[x-1][y][k]<dp[x][y-1][k])
        {
            x--;
            ans+='D';
        }
        else
        {
            y--;
            ans+='R';
        }

        if(x==1)
        {
            for(int i=1;i<y;i++) ans+='R';

            break;
        }
        if(y==1)
        {
            for(int i=1;i<x;i++) ans+='D';
            
            break;
        }
    }
    cout<<dp[n][n][k]<<endl;
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i];
    return 0;

}