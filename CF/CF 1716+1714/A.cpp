#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n,m;
    cin>>n;
    if(n==1) cout<<2<<endl;
    else
    {
        n+=2;
        int ans = n/3;
        cout<<ans<<endl;
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}