#include<bits/stdc++.h>
#define YES cout<<"Alice"<<endl;
#define No cout<<"Bob"<<endl;
using namespace std;


void solve()
{
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m;cin>>m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    if(a[n-1]>=b[m-1])
    {
        YES
    }
    else No

    if(b[m-1]>=a[n-1])
    {
        No
    }
    else YES
    
    
    
}
int main()
{
    ios::sync_with_stdio(false);
    int T;cin>>T;
    while(T--)
    {
        solve();
    }
}