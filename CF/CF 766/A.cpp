#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    int mp[n+1][m+1];int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            if(c=='W')
            {
                mp[i][j]=0;
            }
            else
            {
                mp[i][j]=1;
                cnt++;
            }
        }
    }
    if(!cnt)
    {
        cout<<-1<<endl;
        return ;
    }
    if(mp[r][c]==1)
    {
        cout<<0<<endl;
        return ;
    }
    for(int i=1;i<=n;i++)
        if(mp[i][c])
        {
            cout<<1<<endl;
            return ;
        }
    for(int i = 1;i<=m;i++)
    {
        if(mp[r][i])
        {
            cout<<1<<endl;
            return ;
        }
    }
    cout<<2<<endl;
    return ;
    
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}