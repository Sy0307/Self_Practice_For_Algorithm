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
    int n;
    cin>>n;
    vector<int> a(n+1);
    int ans = 0;
    fr(i,1,n)
    {
        cin>>a[i];
    }
    fr(i,1,n)
    {
        if(a[i]==0)
        {
            if(i%2==0)
            {
                cout<<"YES"<<endl;
                return;
            }
            break;

        }
    }
    ford(i,n,1)
    {
        if(a[i]==0)
        {
            if((n-i+1)%2==0)
            {
                cout<<"YES"<<endl;
                return;
            }
            break;
        }
    }
    cout<<"NO"<<endl;
    
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