#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a,b;
    double ans1,ans2;
    cin>>a>>b;
    if(a==0)
    {
        ans2 = 1;
        ans1 = 0;
    }
    else if(b==0)
    {
        ans2 = 0;
        ans1 = 1;
    }
    else
    {
        double tmp = sqrt(a*a+b*b);
        ans1 = a/tmp;
        ans2 = b/tmp;
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}