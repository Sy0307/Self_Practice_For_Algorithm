#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const ll M =2000000000000000000; 

deque<char> s;
int main()
{
    ios::sync_with_stdio(false);
    ll n,x;    
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        if(c=='U')
        {
            if(s.size()) s.pop_back();
            else s.push_back(c);
        }
        else s.push_back(c);
    //    cout<<x<<endl;
    }
    while(s.size())
    {
        auto c = s.front();
        s.pop_front();
        if(c=='U')
        {
            if(x!=1) x/=2;
        }
        else if(c=='L')
        {
            x*=2;
        }
        else x=x*2+1;

    }
    cout<<x<<endl;
    return 0;
}