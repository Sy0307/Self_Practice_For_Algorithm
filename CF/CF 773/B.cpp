#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n,x,y;
    cin>>n>>x>>y;
    ll k = 0 ;
    ll dp[20][2];
    dp[n][1] = 1;
    dp[n][0] = 0;
    while(n)
    {
        dp[n-1][1] = dp[n][0] + y*dp[n][1];
        dp[n-1][0] =  dp[n][0] + x*dp[n-1][1];
        n--;
    }
    cout<<dp[1][0]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    solve();
}