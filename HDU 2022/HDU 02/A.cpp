#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    string ans = "";
    for(int i=0;i<s.size();i++)
    {
        if(!isdigit(s[i])&&s[i]!='('&&s[i]!=')'&&s[i]!=','&&s[i]!='-')
        {
            continue;
        }
        ans+=s[i];
    }
    cout<<ans<<endl;
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