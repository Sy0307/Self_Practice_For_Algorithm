#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(k<n)
    {
        cout<<0<<endl;
    }
    else 
    {
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            sum += a[i];
        }
        int rest = k - 2*n+1;
        sum+=rest*n;
        cout<<sum<<endl;
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