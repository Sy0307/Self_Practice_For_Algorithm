#include <bits/stdc++.h>
using namespace std;
char ch[3];
long long a[5],ans=10000000000000;
void bt(int hei,long long b[5])
{	if(hei==3)
	{
		ans=min(ans,b[0]);
		return ;
	}
	long long c[5];
	for(int i=0;i<4-hei;i++)
	{
		for(int k=i+1;k<4-hei;k++)
		{
			for(int j=0;j<5;j++)
				c[j]=b[j];
			if(ch[hei]=='*')
				c[i]=c[i]*c[k];
			else
				c[i]=c[i]+c[k];
			for(int j=k;j<4;j++)
				c[j]=b[j+1];
			bt(hei+1,c);
		}
	}
}
int main()
{
	for(int i=0;i<4;i++)
	{
		cin>>a[i];
	}
	a[4]=0;
	for(int i=0;i<3;i++)
	{
		cin>>ch[i];
	}
	bt(0,a);
	cout<<ans<<endl;
	return 0;
}
