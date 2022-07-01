#include<bits/stdc++.h>
using namespace std;

int main()
{
    int total,a,b,c;
    cin>>total>>a>>b>>c;
    int sum = a+b+c;
    total = total%(sum);
    total -=a;
    if(total<0)
    {
        cout<<"F"<<endl;
        return 0;
    }
    total -=b;
    if(total<0)
    {
        cout<<"M"<<endl;
        return 0;
    }
    total -=c;
    if(total<0)
    {
        cout<<"T"<<endl;
        return 0;
    }
    return 0;
    
}