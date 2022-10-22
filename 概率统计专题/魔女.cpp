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

void solve()
{
    double a[10];
    int s = 0;
    fr(i,1,7)
    {
        cin>>a[i];
        s+=a[i];
    }
    double ans = 1;
    fr(i,1,6)
    {
        ans = (ans*a[i]/(s+1-i))*double(i);
    }
    ans = ans*a[7]*7.0;
    cout<<fixed<<setprecision(3)<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}