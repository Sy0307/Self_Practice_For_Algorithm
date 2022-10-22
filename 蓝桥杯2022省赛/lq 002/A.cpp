#include<bits/stdc++.h>
using namespace std;
const int N = 510;

int f[N][N];
int a[N],b[N];
int color[N];
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>color[i];
    memset(f,0x3f,sizeof(f));
  //  cout<<f[0][1]<<endl;
    memset(b,0,sizeof(b));
    memset(a,0,sizeof(a));

    for(int i=1;i<=n;i++)
    {    
        
        if(color[i])
        {
            a[i] = a[i-1]+1;
            b[i] = b[i-1];
        }
        else
        {
            a[i] = a[i-1];
            b[i] = b[i-1]+1;
        }

        f[i][1] = a[i]*b[i];
    }

    for(int i=2;i<=k;i++)
        for(int j=i;j<=n;j++)
            for(int p = i-1;p<j;p++)
            {
                int tmp = (a[j] - a[p]) *(b[j]-b[p]);
                f[j][i] = min(f[j][i],f[p][i-1]+tmp);
            }

    cout<<f[n][k]<<endl;
    return 0;


    return 0;


    
}