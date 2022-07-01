#include<bits/stdc++.h>
using namespace std;

multiset<long long> s;
int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int q;
    cin>>q;
    for(int i=1;i<=5;i++)
    {
        s.insert(-1);
        s.insert(1E18);
    }
    while(q--)
    {
        int flag;
        cin>>flag;
        if(flag==1)
        {
            long long  tmp;cin>>tmp;
            s.insert(tmp);
        }
        else if(flag==2)
        {
            long long  x,k;cin>>x>>k;
            auto it = prev(s.lower_bound(x+1));
            k--;
            while(k--)
            {
                it--;
            }
            cout<<*it<<endl;
        }
        else
        {
            long long x,k;
            cin>>x>>k;
            auto it = s.lower_bound(x);
            k--;
            while(k--)
            {
                it++;
            }
            if(*it<1E18) cout<<*it<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}