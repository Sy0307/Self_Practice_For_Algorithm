#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll f[50000005]={0};
ll mmax(ll a,ll b)
{
    return a>b?a:b;
}
ll make(ll x)
{
    if(x<=3)
        return x;
    else if(x<=50000000&&f[x]>0)
        return f[x];
    else if(x<=50000000)
        return f[x] = mmax(x,make(x/3)+make(x/2)+make(x/4));
    else return mmax(x,make(x/3)+make(x/2)+make(x/4));

}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        ll ans = n;
        if(n>3)
        {
            ans = mmax(n,make(n/2)+make(n/3)+make(n/4));
        }
        cout<<ans<<endl;
        
    }
    return 0;
}