#include<bits/stdc++.h>
using namespace std;

int f[2000010];
int main()
{
    ios::sync_with_stdio(false);
    int k;
    freopen("ans.txt","w",stdout);
    int n ;cin>>n;
    for(int i=0;i<=n;i++)
    {
        int ans = 0;
        for(int j=1;j<=sqrt(i);j++)
        {
            if(i%j==0) ans+=2;
            if(j*j==i&&j==sqrt(i))
                ans--;
        }
        f[i] = ans; 
    }
    for(int i=0;i<=n;i++)
    {
        cout<<f[i]<<",";
    }
    return 0;
}