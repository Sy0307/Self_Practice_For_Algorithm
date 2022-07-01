#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> mp;
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        mp[tmp]++;
    }
    for(int i=1;i<=m;i++)
    {
        int now;
        cin>>now;
        if(mp[now]==0)
        {
            cout<<"No"<<endl;
            return 0;
        }
        else
        {
            mp[now]--;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}