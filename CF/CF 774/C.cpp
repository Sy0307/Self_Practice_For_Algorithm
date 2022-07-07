#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll fac(int x)
{
    ll ans = 1;
    for (int i = 1; i <= x; i++)
    {
        ans *= i;
    }
    return ans;
}
ll f[20];
void solve()
{
    for (int i = 1; i <= 15; i++)
    {
        f[i] = fac(i);
    }
    ll n;
    cin>>n;
    int ans = 200;
    for(int i=0;i<pow(2,15);i++)
    {
        bitset<15> b(i);
        ll t = n;
        for(int j=0;j<15;j++)
        {
            t-=b[j]*f[j];
        }
        if(t>=0)
        {
            bitset<64> c(t);
            ans = min(ans,(int)(c.count()+b.count()));
        }
    }
    cout<<ans<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}