#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    int odd = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]&1) odd++;
    }
    if(odd)
    {
        cout<<n - odd<<endl;
    }
    else
    {
        int ans  = INT_MAX;
        for(int i= 0 ;i<n;i++)
        {
            int cnt = 0;
            while(a[i]%2==0)
            {
                a[i] = a[i]>>1;
                cnt++;
            }
            ans = min(ans,cnt);
        }
        cout<<ans+ n - 1 <<endl;
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}