#include<bits/stdc++.h>
using namespace std;

string mode = "Division ";
int main()
{
    ios::sync_with_stdio(false);
    int n ;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x<1400)
        {
            x = 4;  
        }
        else if(x<1600)
        {
            x = 3;
        }
        else if(x<1900)
        {
            x = 2;
        }
        else x = 1;
        cout<<mode<<x<<endl;
    }
    return 0;
}