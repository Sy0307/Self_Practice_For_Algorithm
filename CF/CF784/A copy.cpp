#include<bits/stdc++.h>
using namespace std;

void make()
{
    int n ; 
    cin>>n;
    int a[200010]={0};    
    int ans = -1;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a[x]++;
        if(a[x]>2) ans = x;
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
        make();
    }
    return 0;
}