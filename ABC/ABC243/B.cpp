#include<bits/stdc++.h>
using namespace std;

int a[1010];
map<int,int> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    int ans1= 0,ans2 = 0;
    int tmp = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp;
        if(a[i]==tmp)
        {
            ans1++;
        }
        else 
        {
            if(mp[tmp]>0) ans2++;
        }
    }
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    return 0;
}