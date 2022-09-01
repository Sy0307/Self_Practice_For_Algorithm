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

void solve()
{
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        int k;
        if(l%i==0)
        {
            k = l;
        }
        else
        {
            k = (l/i+1)*i;
        }
        if(k>r)
        {
            cout<<"NO"<<endl;
            return ;
        }
        a[i] = k;
    }
    cout<<"YES"<<endl;
    fr(i,1,n)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
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