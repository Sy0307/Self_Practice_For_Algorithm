#include<bits/stdc++.h>
using namespace std;

void solve()
{
    bool f =  0;
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans = 0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1]&&!f)
        {
            ans++;
            f = 1;
        }
        else f = 0;

    }
    cout<<ans<<endl;
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