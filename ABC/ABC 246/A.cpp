#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;

int a[10],b[10];
int record[1010];
int record2[1010];
int main()
{
    ios::sync_with_stdio(false);
    memset(record,0,sizeof(record));
    for(int i=1;i<=3;i++)
    {
        cin>>a[i];
        cin>>b[i];
    }
    for(int i=1;i<=3;i++)
    {

        record[a[i]+101]++;
        record2[b[i]+101]++;
    }
    int ans1 = INT_MAX,ans2 = INT_MAX;
    for(int i=1;i<=3;i++)
    {
            
            if(record[a[i]+101]==1)
            {
                ans1 = a[i];
            }


            if(record2[b[i]+101]==1)
            {
                ans2 = b[i];
            }

    }
    cout<<ans1<<" "<<ans2<<endl;

    return 0;
}