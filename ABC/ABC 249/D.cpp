#include<bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int cnt[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    using ll  = long long;
    ll ans  = 0;
    for(int i=1;i<=200000;i++)
    {
        for(int j=i;j<=200000;j+=i)
        {
            ans+=(ll)(cnt[j])*(ll)(cnt[i])*(ll)(cnt[j/i]);
        }
    }
    cout<<ans<<endl;
    return 0;

}