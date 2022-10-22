#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n,l,r,k;
    cin>>n>>l>>r>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int ans = 0;
    for(auto &now:a)
    {
        if(now<l||now>r)
            continue;
        if(k>=now)
        {
            k-=now;
            ans++;
        }
    }
    cout<<ans<<endl;
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