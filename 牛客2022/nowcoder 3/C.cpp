#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;

int dp[maxn][4] = {0};
int edge[maxn][4] = {0};

int main()
{
    ios::sync_with_stdio(false);
    memset(dp, 0x3f, sizeof(dp));
    int n;
    int s1,t1,s2,t2;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j = 0;j<4;j++)
        {
            cin>>edge[i][j];
        }
    }
    cin>>s1>>t1>>s2>>t2;
    dp[s1][0]
}