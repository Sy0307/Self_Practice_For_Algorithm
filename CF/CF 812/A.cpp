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
    ll n;
    cin>>n;
    int maxx = 0,minx = 0,maxy =0,miny = 0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        maxx = max(maxx,x);
        minx = min(minx,x);
        maxy = max(maxy,y);
        miny = min(miny,y);
    }
    cout<<2*(maxx-minx+maxy-miny)<<endl;
    
}
int main()
{
    ios::sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}