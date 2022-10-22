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

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    fr(i,1,n)
    {
        cin>>a[i];
        a[i]--;
    }
    ll c1 = 0,c2 = 0,c3 = 0;
    fr(i,1,n)
    {
        if(a[i]>0)
        {
            c1++;
        }
        else if(a[i]<0)
        {
            c2++;
        }
    }
    ll ans = 0;
    fr(i,1,n)
    if(!a[i])
    {
        c3++;
        ans+=n - c3;
    }
    ans+=c1*c2;
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}