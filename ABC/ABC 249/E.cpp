#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll f[3100][3100];
ll g[3100][3100];
int cal(int x)
{
    int ans = 0;
    while(x)
    {
        ans++;
        x/=10;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,p;
    cin>>n>>p;
    if(n<=2)
    {
        cout<<0<<endl;
        return 0;
    }
    f[0][0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=2*i&&j<n;j++)
        {
            {
                int t = j - cal(i) - 1;
                if (t >= 0) f[i][j] += 26 * f[0][t] % p;
            }
            {
                int x = max(1, i - 9), y = i - 1;
                int t = j - 1 - 1;
                if (t >= 0 && y >= 1) f[i][j] += 25 * (g[t][y] - g[t][x - 1]) % p;
            }
 
            {
                int x = max(1, i - 99), y = i - 10;
                int t = j - 2 - 1;
                if (t >= 0 && y >= 1) f[i][j] += 25 * (g[t][y] - g[t][x - 1]) % p;
            }
            {
                int x = max(1, i - 999), y = i - 100;
                int t = j - 3 - 1;
                if (t >= 0 && y >= 1) f[i][j] += 25 * (g[t][y] - g[t][x - 1]) % p;
            }
            {
                int x = 1, y = i - 1000;
                int t = j - 4 - 1;
                if (t >= 0 && y >= 1) f[i][j] += 25 * (g[t][y] - g[t][x - 1]) % p;
            }
            f[i][j] %= p;
            g[j][i] = g[j][i - 1] + f[i][j];
        }


        }
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        ans = (ans+f[n][i])%p;

    }
    cout<<ans%p<<endl;

}