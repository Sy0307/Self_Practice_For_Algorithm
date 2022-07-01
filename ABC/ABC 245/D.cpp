#include<bits/stdc++.h>
using namespace std;

int ans[102];
int a[102];
int c[204];
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=n+m;i++)
    {
        cin>>c[i];
    }

    for(int j=m;j>=0;j--)
    {
        ans[j] = c[j+n]/a[n];
        for(int i=0;i<=n;i++)
        {
            c[i+j] -= ans[j]*a[i];
        }
    }
    for(int i=0;i<=m;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
    
}