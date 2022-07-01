#include<bits/stdc++.h>
using namespace std;
map<string ,int> mp;
string s1[1000],s2[1000];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    mp.clear();
    for(int i=1;i<=n;i++)
    {
        string x,y;
        cin>>x>>y;
        mp[x]++;
        mp[y]++;   
        s1[i] = x;
        s2[i] = y;
    }
    for(int i=1;i<=n;i++)
    {
        if(mp[s1[i]]==1||mp[s2[i]]==1)
            continue;
        else 
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}