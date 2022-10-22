#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 10005;
const double pi = 3.1415926535897932;
const double pi2 = 2*pi;

struct Point
{
	double x, y;
};

inline double sqr(double x)
{
	return x*x;
}

inline double get_dist(Point x, Point y)
{
	return sqrt(sqr(x.x-y.x) + sqr(x.y-y.y));
}

struct Circle
{
	Point O;
	double r;
} c[maxn];

inline double get_dist(Circle x, Circle y)
{
	return get_dist(x.O, y.O);
}

int n;

struct Fugai
{
	double l, r;

	inline bool operator < (const Fugai& other) const
	{
		return l < other.l;
	}
} fugai[maxn];

int nown;
inline void cha(double l, double r)
{
	fugai[++nown] = (Fugai)
	{
		l, r
	};
}

bool gaif = false;//gaif = true表示该圆盘被上面的大圆盘完全覆盖

inline void jiao(Circle A, Circle B)
{
	double dist = get_dist(A, B);
	if(dist > A.r+B.r || A.r + dist < B.r)//没有任何覆盖
		return;
	if(dist + B.r < A.r)//如果被一个大圆盘完全覆盖，直接跳出
	{
		gaif = true;
		return;
	}
	double alpha = acos((sqr(B.r)+sqr(dist)-sqr(A.r))/(B.r*dist*2.));//上图中的角CAD
	double beta = atan2(B.O.y-A.O.y, A.O.x-B.O.x);//上图中的角CAE
	double jiao1 = beta-alpha;//线段覆盖中的l
	double jiao2 = beta+alpha;//线段覆盖中的r
	if(jiao1 < 0 && jiao2 < 0)//对极角的一些特判
	{
		jiao1 += pi2, jiao2 += pi2;
	}
	if(jiao1 >= 0 && jiao2 <= pi2)
		cha(jiao1, jiao2);
	else
	{
		if(jiao1 < 0)
		{
			cha(jiao1+pi2, pi2);
			cha(0, jiao2);
		}
		else
		{
			cha(jiao1, pi2);
			cha(0, jiao2-pi2);
		}
	}
}

inline double get_ans()
{
	double ans = 0;
	sort(fugai+1, fugai+nown+1);
	double lastr = fugai[1].l;
	for(int i = 1; i <= nown; ++i)
	{
		if(lastr >= fugai[i].r)
			continue;
		if(fugai[i].l > lastr)
			ans += fugai[i].r - fugai[i].l;
		else
			ans += fugai[i].r - lastr;
		lastr = fugai[i].r;
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lf%lf%lf", &c[i].O.x, &c[i].O.y,&c[i].r);
	double ans = 0;
	for(int i = n; i; --i)
	{
		nown = 0;
		for(int j = n; j > i; --j)//枚举所有该圆盘之后的圆盘
		{
			jiao(c[j], c[i]);
			if(gaif)
				break;
		}
		if(gaif)
			gaif = false;
		else
			ans += (pi2-get_ans())*c[i].r;
		nown = 0;
	}
	printf("%.9f", ans);
	return 0;
}