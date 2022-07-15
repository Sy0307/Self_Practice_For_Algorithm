#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    if(k==1)
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<i<<endl;;
        }
        return ;
    }
    if(n&1)
    {
        cout<<"NO"<<endl;
        return ;
    }
    else 
    {
        cout<<"YES"<<endl;
        int t1 = 1;
        int t2 = 2;
        for(int i=1;i<=n;i++)
        {

            for(int j=1;j<=k;j++)
            {
                if(i&1)
                {
                    cout<<t1<<" ";
                    t1+=2;
                }
                else 
                {
                    cout<<t2<<" ";
                    t2+=2;
                }
            }
            cout<<endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}