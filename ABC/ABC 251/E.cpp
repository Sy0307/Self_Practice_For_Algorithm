#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
ll dp[300005][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    ll ans = 1e18;
    vector<int> a(n+1,0);
    for(int i =1;i<=n;i++)
        cin>>a[i];
    dp[1][0] = 1e18,dp[1][1] = a[1];
    for(int i=2;i<=n;i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = min(dp[i-1][0],dp[i-1][1])  + a[i];
    }
    ans = min(dp[n][0],dp[n][1]);
    memset(dp,0x3f,sizeof(dp));
    dp[1][1] = 1e18,dp[1][0] = 0;
    for(int i=2;i<=n;i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = min(dp[i-1][0],dp[i-1][1])  + a[i];
    }
    ans = min(ans,dp[n][1]);
    
    cout << ans << endl;
    return 0;
}