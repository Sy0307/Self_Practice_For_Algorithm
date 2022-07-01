/*  

Copied
就是找一个1x6 或者 6x1 的格子
或者全是对角线的格子
寻求4个以上的“#”即可
太蠢了应该能做的，以前做过差不多的


*/


#include<iostream>
using namespace std;
int N;
string S[1000];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>S[i];
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)
	{
		for(int r=0;r<4;r++)
		{
			int dx=r<=1?1:r==2?0:-1;
			int dy=r==0?0:1;
			int cnt=0;
			for(int t=0;t<6;t++)
			{
				int x=i+dx*t,y=j+dy*t;
				if(x<0||y<0||x>=N||y>=N)
				{
					cnt=3;
					break;
				}
				if(S[x][y]=='.')cnt++;
			}
			if(cnt<=2)
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
}