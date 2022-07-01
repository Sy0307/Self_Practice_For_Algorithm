#include<bits/stdc++.h>
using namespace std;
const int N = 3010;
using ll= long long ;
ll f[N][N][2];
int main()
{
    ios::sync_with_stdio(0);
    int n;
    int mod;
    cin>>n>>mod;
    f[1][0][1] = 1;
    f[1][1][0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++)
        {
            f[i][j][1] += f[i-1][j][1];
            if(j>0)
            {
                f[i][j][1] += f[i-1][j-1][1]*3;
            }
            f[i][j][1] += f[i-1][j][0];
            if(j>0) f[i][j][0] += f[i-1][j-1][0];
            if(j>1) f[i][j][0] += f[i-1][j-2][1]*2;
            f[i][j][1]%=mod;
            f[i][j][0]%=mod;
        }
    }
    for(int i=1;i<=n-1;i++)
    {
      cout<<f[n][i][1]<<" ";
    }
    return 0;
}