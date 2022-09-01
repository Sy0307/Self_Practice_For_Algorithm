#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define ford(i, a, b) for(int i = a; i >= b; i--)
#define forall(i, a) for(auto &i : a)


ll a[maxn];
ll s[maxn];
void solve()
{
    ll n,p,q,r;
    cin>>n>>p>>q>>r;
    fr(i,1,n)
    {
        cin>>s[i];
    }
    fr(i,1,n)
    {
        a[i] =a[i-1]+s[i];
    }
    fr(i,0,n)
    {
        auto f1 = lower_bound(a+1,a+n,a[i]+p) - a;
        if(a[f1] - a[i]!=p||f1>n)
        {
            continue;
        }
        auto f2 = lower_bound(a+1,a+n,a[f1]+q) - a;
        if(a[f2] - a[f1]!=q||f2>n)
        {
            continue;
        }
        auto f3 = lower_bound(a+1,a+n,a[f2]+r) - a;
        if(a[f3] - a[f2]!=r||f3>n)
        {
            continue;
        }
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}