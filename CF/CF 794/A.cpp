#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    int tot = 0;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
        tot+=a[i];
    }

    for(int i=0;i<n;i++)
    {
        double now = (tot - a[i])/(double)(n-1);
        if(now==a[i])
        {
        //    cout<<now<<endl;
            cout<<"YES"<<endl;
            return ;
        }
    }
    cout<<"NO"<<endl;
    
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