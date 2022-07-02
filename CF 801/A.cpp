#include<bits/stdc++.h>
using namespace std;

int n,m;
int get(int x,int y)
{
    return max({x*y,(n-x+1)*y,(m-y+1)*x,(n-x+1)*(m-y+1)});
}
void solve()
{
    cin>>n>>m;
    
    int maxx = INT_MIN;
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
        for(int j= 1;j<=m;j++)
        {
            int x;
            cin>>x;
            if(x>maxx)
            {
                maxx = x;
                ans = get(i,j);
            }
            else if(x==maxx&&get(i,j)<ans)
            {
                ans = get(i,j);
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}