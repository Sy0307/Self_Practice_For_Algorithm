#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(a<b) return gcd(b,a);
	while(b)
	{
		int tmp = a%b;
		a = b; 
		b = tmp;
	}
	return a;
}

int get(int a,int b)
{
	return a*b/gcd(a,b);
}

int f[2030];

int main()
{
	memset(f,0x7f,sizeof(f));
	f[1] = 0;
	for(int i=1;i<=2021;i++)
		for(int j=1;j<=21&&i-j>=0;j++)
		{
			f[i] = min(f[i],f[i-j]+get(i,i-j));
		}
	cout<<f[2021]<<endl;;
}