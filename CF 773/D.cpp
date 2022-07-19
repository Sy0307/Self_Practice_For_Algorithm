#include<bits/stdc++.h>
using namespace std;

void solve()
{
    using pii = pair<int, int>;
    using ll = long long;
    int n;
    cin>>n;
    vector<int> a(n);
    vector<pii> ans;
    vector<int> split;
    map<int,int> cnt;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(auto &now:cnt)
    {
        if(now.second&1) 
        {
            cout<<-1<<endl;
            return ;
        }
    }
    int res = 1;
    for(int i=1;i<=n&&a.size();i++)
    {
        auto it = ++a.begin();
        while(*it!=*a.begin())
        {
            it++;
        }
        auto t = it - a.begin();
        for(int j = 0;j<t-1;j++)
            ans.push_back({res+j+t,a[j+1]});
        reverse(a.begin(),it);
        a.erase(a.begin()+t-1);
        a.erase(a.begin()+t-1);

        res+=t*2;
        split.push_back(t*2);
    }
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans)
    {
        cout<<x<<" "<<y<<endl;
    }
    cout<<split.size()<<endl;
    for(auto x:split)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while (T--)
    {
        solve();
    }
    
}