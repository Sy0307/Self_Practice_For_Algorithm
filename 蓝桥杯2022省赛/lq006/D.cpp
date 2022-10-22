#include<bits/stdc++.h>
using  namespace std;

int a[1000010];
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int t = k*2+1;
    if(n<=t)
    {
        cout<<1<<endl;
        int ans = max(1,n-k);
        cout<<ans<<endl;
    }
    else if(n>t)
    {
        int ans = 0;
        if(n%t>k||!(n%t))
        {
            
            for(int i=k;i<n;i+=t)
            {
                a[++ans] = i+1;
            }
        }
        else
        {
            for(int i=0;i<n;i+=t)
            {
                a[++ans] = i+1;
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=ans;i++)
            cout<<a[i]<<" ";
        
    }
    return 0;
}
