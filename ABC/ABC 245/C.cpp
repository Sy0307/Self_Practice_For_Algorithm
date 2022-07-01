#include<bits/stdc++.h>
using namespace std;

int a[200010];
int b[200010],f[200010][3];
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    f[1][1] = f[1][2] = 1;
    for(int i=2;i<=n;i++)
    {
        if(abs(a[i]-b[i-1])<=k)
        {
            f[i][1] |=f[i-1][2];
        }
        if(abs(a[i]-a[i-1])<=k)
        {
            f[i][1] |=f[i-1][1];
        }
        if(abs(b[i]-b[i-1])<=k)
        {
            f[i][2] |=f[i-1][2];
        }
        if(abs(b[i]-a[i-1])<=k)
        {
            f[i][2] |=f[i-1][1];
        }
    }

    if(f[n][1]||f[n][2])
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}