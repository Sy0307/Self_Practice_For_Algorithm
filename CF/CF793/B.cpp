#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int x;
    int ans = -1;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x!=i)
        {
            ans&=i;
        }
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