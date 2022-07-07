#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    using PII = pair<int,int>;
    priority_queue<PII,vector<PII>> q;
    for(int i=0;i<n;i++)
    {
        q.push(make_pair(a[i]+i,i));
    }
    while(m--)
    {
        auto now = q.top();
   //     cout<<now.first<<endl;
        a[now.second] = 0;
        q.pop();
    }
    int cnt = 0;
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            cnt++;
        }
        else
        {
            ans+=cnt+a[i];
        }

    }
    cout<<ans<<endl;
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}