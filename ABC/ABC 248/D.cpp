#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<vector<int>> a(n+1);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[x].push_back(i);
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,k;
        cin>>x>>y>>k;
        auto t1 = lower_bound(a[k].begin(),a[k].end(),x);
        auto t2 = lower_bound(a[k].begin(),a[k].end(),y+1);
        cout<<t2-t1<<endl;
    }
    return 0;
}