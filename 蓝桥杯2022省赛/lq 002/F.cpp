#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
using ll = long long;
ll l,r,k;
int judge(ll x)
{
    stack<int> a;
    int ans = 0;
    while(x)
    {
        a.push(x%10);
        x/=10;
    }
    bool f = 1;
    while(a.size())
    {
        if(f)
        {
            f = 0;
            ans+= a.top();
        }
        else
        {
            f = 1;
            ans-=a.top();
        }
        a.pop();
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>l>>r>>k;
    if(l==r)
    {
        ll x = l;
        cout<<(judge(x)==k)<<endl;
    }
    else
    {
        ll ans = 0;
        for(int i=l;i<=r;i++)
            if(judge(i)==k)
                ans = (ans+i)%mod;
        cout<<ans<<endl;
    }
    return 0;
}