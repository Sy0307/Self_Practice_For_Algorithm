#include<bits/stdc++.h>
using namespace std;

using ll = long long ;
ll f[2033];
int main()
{
    memset(f,0x7f,sizeof(f));
    f[0] = 0;
    for(int i=1;i<=2021;i++)
        for(int j=0;j<i;j++)
        {
            f[i] = min(f[i],1+2*f[j]+3*f[i-j-1]+j*j*(i-j-1));
        }
    cout<<f[2021]<<endl;
}