#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    if(s.size()==2)
    {
        cout<<s[1]<<endl;
    }
    else 
    {
        char key = '9';
        for(int i=0;i<s.size();i++)
        {
            key = min(key,s[i]);
        }
        cout<<key<<endl; 
    }
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