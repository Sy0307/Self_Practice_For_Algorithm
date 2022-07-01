#include<bits/stdc++.h>
using namespace std;

bool vis[2010];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        vis[tmp] = 1;
    }
    for(int i=0;i<=2000;i++)
    {
        if(!vis[i])
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<2001<<endl;
}