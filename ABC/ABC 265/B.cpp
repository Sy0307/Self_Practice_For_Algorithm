#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define ford(i, a, b) for(int i = a; i >= b; i--)
#define forall(i, a) for(auto &i : a)

ll n, m, t;
ll a[maxn];
ll c[maxn];
void solve()
{
    cin >> n >> m >> t;
    fr(i, 1, n-1)
    {
        cin >> a[i];
    }
    memset(c,0,sizeof(c));
    fr(i, 1, m)
    {
        int x, y;
        cin >> x >> y;
        c[x] = y;
    }
    ll now = t;
    fr(i,1,n)
    {
        now+=c[i];
        now-=a[i];
        // cout<<now<<endl;
        if(now<=0) 
        {
         //   cout<<i<<endl;;
            cout<<"No"<<endl;
            return ;
        }

    }
    cout<<"Yes"<<endl;;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}