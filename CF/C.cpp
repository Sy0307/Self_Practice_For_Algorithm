#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i-1];
    }
    using ll = long long ;
    bool f = 0;ll tot = 0;
    for(int i=0;i<n;i++)
    {
        if(f&&a[i]!=0)
        {
            cout<<"No"<<endl;
            return;
        }
        tot+=a[i];
        if(tot<=0) f = 1;
    }
    if(tot!=0)
    {
        cout<<"No"<<endl;
        return ;
    }
    cout<<"Yes"<<endl;
    
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