#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

const int maxn = 2e5+1000;
struct node
{
    ll time,val;
}a[maxn];
ll n,q;
void solve()
{
    cin>>n>>q;
    ll sum = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].val;
        a[i].time = 0;
        sum+=a[i].val;
    }
    ll allchange = -1,changeval = 0;
    for(int i=1;i<=q;i++)
    {
        int signal;
        cin>>signal;
        if(signal==1)
        {
            ll x,y;
            cin>>x>>y;
            if(allchange<a[x].time)
            {
                sum-=a[x].val;
                sum+=y;
            //    cout<<sum<<endl;
            }
            else
            {
                sum-=changeval;
                sum+=y;
            }
            a[x].time = i;
            a[x].val = y;
        }
        else if(signal==2)
        {
            int x;
            cin>>x;
            sum = n*x;
            allchange = i;
            changeval = x;   
        }
        cout<<sum<<endl;
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}