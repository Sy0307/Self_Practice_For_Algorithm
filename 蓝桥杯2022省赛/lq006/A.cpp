#include<bits/stdc++.h>
using  namespace std;

int x[10010],y[10010];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    int xx = x[n/2+1];
    int yy = y[n/2+1];
    int ans = 0;

    for(int i=1;i<=n;i++)
    {
        ans+=abs(xx - x[i]);
        ans+=abs(yy - y[i]);
    }
    cout<<ans<<endl;
    return 0;
}