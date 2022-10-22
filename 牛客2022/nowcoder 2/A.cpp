#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    int k = ceil(sqrt(n) - 0.0000001);
   // cout<<k<<endl;
    for(int i =1;i<=n;i+=k)
    {
        if(i+k<=n)
            reverse(a.begin()+i,a.begin()+i+k);
        else 
            reverse(a.begin()+i,a.end());
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
}