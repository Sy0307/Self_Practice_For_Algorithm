#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int in[2005];
void solve()
{
    int n,x;
    cin>>n;
    cin>>x;
    memset(in,0,sizeof(in));
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        in[a]++;
        in[b]++;
    }
    if(n==1||in[x]==1)
    {
        cout<<"Ayush"<<endl;
        return ;
    }
    else
    {
        if(n&1) cout<<"Ashish"<<endl;
        else cout<<"Ayush"<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}