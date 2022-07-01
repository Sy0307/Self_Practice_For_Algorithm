#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int main()
{
    ios::sync_with_stdio(false);
    int n;cin>>n;

    vector<int> a(n+1);
    vector<int> cnt(N,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=N;i++)
    {
        cnt[i]+=cnt[i-1];
    }
    
    using ll = long long;
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans+=(ll)cnt[a[i] -1]*(n - cnt[a[i]]);
    }
    cout<<ans<<endl;
    return 0;

}