#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    char key = s[n/2];
    int ans = 0;
    for(int i=n/2;i>=0;i--)
    {
        if(s[i]==s[n/2])
        {
            ans++;
        }
        else break;
    }

    for(int i=n/2+1;i<n;i++)
    {
        if(s[i]==key)
        {
            ans++;
        }
        else break;
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