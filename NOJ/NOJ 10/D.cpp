#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

ll Find(int x)
{
    fr(i,2,sqrt(x))
    {
        if(x%i==0)
        {
            return i;
        }
    }
    return x;
}
ll gcd(ll a,ll b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
void solve()
{
    int n;cin>>n;
    vector<ull> a(n+1);
    int k1,k2;
    cin>>k1>>k2;
    fr(i,2,n)
    {
        ll x,y;
        cin>>x>>y;
        a[i] = x*y;
    }
    fr(i,2,n)
    {
        k1 = gcd(k1,a[i]);
        k2 = gcd(k2,a[i]);
    }
    if(k1==1&&k2==1)
    {
        cout<<-1<<endl;
    }
    else 
    {
        if(k1>1)
        {
            cout<<Find(k1)<<endl;
        }
        else
        {
            cout<<Find(k2)<<endl;
        }
    }
    
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}