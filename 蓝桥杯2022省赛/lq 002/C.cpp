#include<bits/stdc++.h>
using namespace std;

struct line{
    int x, y;
}a[5010];
bool cmp(line a,line b)
{
    return a.x<b.x;
}
int x,y,n;
int f[5010]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin>>x>>y>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    sort(a+1,a+1+n,cmp);
    
    for(int i=1;i<=n;i++) f[i] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        if(a[j].y<a[i].y)
            f[i] = max(f[i],f[j]+1);
    }

    int ans = 0;
    for(int i=1;i<=n;i++)
        ans = max(ans,f[i]);
    cout<<ans<<endl;


    return 0;
}