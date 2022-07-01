#include<bits/stdc++.h>
using namespace std;

int a[10]={0};
int main()
{
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    int cnt = 3;
    int now = 0;
    while(cnt--)
    {
        now = a[now];
    }
    cout<<now<<endl;
    return 0;
}