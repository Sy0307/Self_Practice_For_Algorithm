#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a,b,c;
    cin>>a>>b>>c;
    if(b>=a&&b<=c)
    {
        cout<<"Yes"<<endl;
    }
    else if(b<=a&&b>=c)
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    return 0;
}