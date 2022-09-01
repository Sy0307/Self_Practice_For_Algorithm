#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
ll ksm(ll a ,ll k) //a代表底数，k代表大指数
{
    ll rec = 1;
    while( k )
    {
        if (k & 1)
            rec *= a;
        a *= a;
        k >>= 1;
    }
    return rec;
}
void solve()
{
    long long  n,m;
    cin>>n>>m;
    ll ans = (n-m) * 500000004 % MOD;

    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
}