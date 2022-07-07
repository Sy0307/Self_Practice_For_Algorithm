#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int a = 0,b = 0;
    while(n--)
    {
        int x;cin>>x;
        if(x&1)a++;
        else b++;
    }
    cout<<min(a,b)<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}