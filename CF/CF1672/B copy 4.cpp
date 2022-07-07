#include<bits/stdc++.h>
using namespace std;
bool make()
{
    int n;
    cin>>n;
    int a[200010],b[200010];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
        cin>>b[i];
    int i = 1, j = 1;
    bool f = 1;
    map<int,int> mp;
    while(j<=n)
    {
        if(i<=n&&a[i]==b[j])
        {
            i++;j++;
        }
        else
        {
            if(mp[b[j]]&&b[j]==b[j-1])
            {
                mp[b[j]]--;
                j++;
            }
            else if(i<=n)
            {
                mp[a[i]]++;
                i++;
            }
            else 
            {
                f = 0;
                break;
            }
        }

    }
    return f;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {

        if(make()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;

}