#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    multiset<int> s;
    int Q;
    cin>>Q;
    while(Q--)
    {
        int sign;
        int a,b;
        cin>>sign;
        if(sign==1)
        {
            cin>>a;
            s.insert(a);
        }
        else if(sign ==2)
        {
            cin>>a>>b; 
            for(int i = 0;i<b;i++)
            {
                auto it = s.lower_bound(a);
                if(it==s.end())
                {
                    break;
                }
                else if(*it!=a)
                {
                    break;
                }
                s.erase(it);
            }
        }
        else
        {
            int p1 = *prev(s.end());
            int p2 = *s.begin();
            cout<<p1 - p2<<endl;
        }
    }
    
}