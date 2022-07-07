#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    vector<int> a;
    for(int i= 0 ;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            a.push_back(i);
        }
    }
    if(a.size()&&k>= n-  a.back() -1)
    {
        swap(s[a.back()] , s[n-1]);
        k-= n - a.back() -1;
        a.pop_back();
    }
    //
    if(a.size()&&k>=*a.begin())
    {
        swap(s[0],s[*a.begin()]);
    }
    //
    int ans = 0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i - 1]=='1')
        {
            ans+=10;
        }
        if(s[i]=='1')
        {
            ans++;
        }
    }
    cout<<ans<<endl ;
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