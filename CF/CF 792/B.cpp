#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    using ll = long long;
    ll x,y,z;
    y = b;z = c;
    x = z/y*y+a;
    if(x<=z) x+=y;
    cout<<x<<" "<<y<<" "<<z<<endl;
    
    
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