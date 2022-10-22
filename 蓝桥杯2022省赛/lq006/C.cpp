#include<bits/stdc++.h>
using namespace std;
const int N  =1e6+10;

int l[N];
int r[N];
int main()
{
    ios::sync_with_stdio(false);
    int n ;
    string s ;
    cin>>s;
    n = s.size();
    for(int i=1;i<n;i++)
    {
        l[i] = l[i-1];
        if(s[i]==s[i-1]&&s[i]=='v') l[i]++;
    }
    for(int i=n-2;i>=0;i--)
    {
        r[i] = r[i+1];
        if(s[i]==s[i+1]&&s[i]=='v') r[i]++;
    }
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='o') ans+=(long long )l[i-1]*r[i+1];

    }
    cout<<ans<<endl;
    return 0;
}