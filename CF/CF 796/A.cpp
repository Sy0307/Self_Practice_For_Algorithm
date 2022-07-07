#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int x;
    cin>>x;
    int ans = x&(-x);
    if((ans xor x)==0) ans++;
    if(x==1) ans = 3;
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}