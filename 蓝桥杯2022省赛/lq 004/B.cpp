#include<bits/stdc++.h>
using namespace std;


string ss[20];
int w[20];
bool check(string &s,string &t,int l,int r)
{
    for(int i=l;i<=r;i++)
        if(t[i-l]!=s[i]) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        cin>>ss[i];
        cin>>w[i];
    }
    string s;
    cin>>s;
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        int sz = ss[i].size();
        int t = 0;
    //    cout<<sz<<endl;
        for(int j=0;j<=s.size()-sz;j++)
        {
            if(check(s,ss[i],j,j+sz-1)) t++;
        }
    //    cout<<t<<endl;
        ans+=w[i]*t;
    }
    cout<<ans<<endl;
    return 0;
}