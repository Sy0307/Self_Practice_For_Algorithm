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

map<int,int> mp;
void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    fr(i,a,b)
    {
        mp[i]++;
    }
    fr(i,c,d)
    {
        mp[i]++;
    }
    int ans = 0;
    fr(i,0,100)
    {
        if(mp[i]>1)
        {
            ans++;
        }
    }
    cout<<max(ans-1,0)<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}