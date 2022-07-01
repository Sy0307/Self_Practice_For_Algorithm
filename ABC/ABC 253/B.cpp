#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> a;
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c; 
            if(c=='o')
            {
                a.push_back(make_pair(i,j));
            }
        }
    }
    int ans = INT_MAX;
    n = a.size();
    for(int i=  0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            ans = min(ans,abs(a[i].first - a[j].first)+ abs(a[i].second - a[j].second));
        }
    }
    cout<<ans<<endl;

}