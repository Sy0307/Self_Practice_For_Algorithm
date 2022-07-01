#include<bits/stdc++.h>
using namespace std;

bool vis[1010]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int tot = 2*n+1;
    cout<<1<<endl;
    vis[1] = 1;
    for(int i =1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        vis[tmp] = 1;
        bool f  = 1;
        for(int j=2;j<=tot&&f;j++)
        {
            if(!vis[j])
            {
                cout<<j<<endl;
                vis[j] = 1;
                f = 0 ;
            }
        }
    }
    return 0;
}