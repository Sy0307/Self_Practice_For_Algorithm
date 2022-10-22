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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

pll a[maxn];
void solve()
{
    int n;
    cin>>n;
    fr(i,1,n)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+n+1);
    ll MAXR = -INT_MAX , ans = 0;
    fr(i,1,n)
    {
        if(MAXR<=a[i].second)
        {
            ans +=a[i].second - max(MAXR,a[i].first)+1;
            MAXR = a[i].second+1;
        }
    }
    cout<<ans<<endl;
   
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}