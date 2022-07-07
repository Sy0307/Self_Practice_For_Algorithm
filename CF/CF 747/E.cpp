#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int  mod  = 1e9+7;
int main()
{
    ios::sync_with_stdio(false);
    int x;
    cin>>x;
    int a[70];
    a[1] = 1;
    for(int i=2;i<=x;i++)
    {
        a[i] = a[i-1]*a[i-1]%mod*16%mod;
    }
    cout<<6*a[x]%mod<<endl;
    
}