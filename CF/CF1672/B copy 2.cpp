#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int a[200010]={0};
        int n;
        cin>>n;
        int t1,t2;
        t1 =t2 = -1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==a[i-1])
            {
                if(t1==-1)
                {
                    t1 = i;
                }
                t2 = i;
            }
        }
        if(t1==t2) cout<<0<<endl;
        else 
        {
            int ans = max(1,t2 - t1 - 1);
            cout<<ans<<endl;
        }
    }
    return 0;


}