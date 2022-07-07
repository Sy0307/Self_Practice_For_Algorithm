#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b;
    cin>>a>>b;
    int t =min(a,b);
    a-=t;
    b-=t;
    for(int i=1;i<=t;i++)
    {
        cout<<"01";
    }
    if(a)
    {
        for(int i=1;i<=a;i++)
        {
            cout<<"0";
        }
    }
    else 
    {
        for(int i=1;i<=b;i++)
        {
            cout<<"1";
        }
    }
    cout<<endl;
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