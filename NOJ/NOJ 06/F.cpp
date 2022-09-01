#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> pre(n + 1);
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x ; 
        cin>>x;
        pre[i] = x +  pre[i - 1];
    }
    int ans = pre[n];
    for(int i=n - 1;i>1;i--)
    {
        ans = max(ans, pre[i] - ans);
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}