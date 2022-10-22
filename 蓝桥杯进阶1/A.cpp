#include<bits/stdc++.h>
using namespace std;

map<pair<double,double>,int> mp;
int main()
{
    int ans = 0;
    for(int x1=0;x1<=19;x1++)
        for(int y1=0;y1<=20;y1++)
            for(int x2=0;x2<=19;x2++)
                for(int y2=0;y2<=20;y2++)
                {
                    if(x1!=x2&&y1!=y2)
                    {
                        double d = (y1-y2)/(x1-x2);
                        double b = (x2*y1-x1*y2)/(x2-x1);
                        if(mp[{d,b}]==0)
                        {
                            mp[{d,b}] =1;
                            ans++;
                        }
                    }
                }

    cout<<ans<<endl;

}