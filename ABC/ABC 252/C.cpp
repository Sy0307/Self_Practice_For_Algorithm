#include<bits/stdc++.h>
using namespace std;

int a[12][110];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
 //   vector<int> cnt(20,INT_MAX);
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<10;j++)
        {
            char d = s[j];
            int x = d-'0';
            a[x][i] = j;
        //    cnt[i] = min(cnt[i],)
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<=9;i++)
    {
        int now = 0;
        map<int,int> mp;
        for(int  j= 1;j<=n;j++)
        {
            now = max(a[i][j],now);
            mp[a[i][j]]++;
        }
        for(int j=0;j<=9;j++)
            now= max(now,(mp[j] - 1)*10 + j);
        ans = min(ans,now);

    }
    cout<<ans<<endl;
    return 0;
}