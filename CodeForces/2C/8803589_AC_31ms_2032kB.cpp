#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
#include<time.h>
using namespace std;
void fre(){freopen("c://test//input.in","r",stdin);freopen("c://test//output.out","w",stdout);}
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define MP(x,y) make_pair(x,y)
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
template <class T> inline void gmax(T &a,T b){if(b>a)a=b;}
template <class T> inline void gmin(T &a,T b){if(b<a)a=b;}
const int N=0,M=0,Z=1e9+7,ms63=1061109567;
struct Circle
{
	double x,y,r;
}c[3];
double ang[3];
const int dy[4]={-1,0,0,1};
const int dx[4]={0,-1,1,0};
double K(double x)
{
	return x*x;
}
double Dis(double x,double y,double xx,double yy)
{
	return sqrt(K(x-xx)+K(y-yy));
}
double Val(double x,double y)
{
	for(int i=0;i<3;++i)ang[i]=Dis(x,y,c[i].x,c[i].y)/c[i].r;
	double val=0;
	for(int i=0;i<3;++i)val+=K(ang[i]-ang[(i+1)%3]);
	return val;
}
int main()
{
	double x=0,y=0;
	for(int i=0;i<3;++i)
	{
		scanf("%lf%lf%lf",&c[i].x,&c[i].y,&c[i].r);
		x+=c[i].x/3;y+=c[i].y/3;
	}
	double err=Val(x,y);
	double step=1;
	for(int tim=1;tim<=1e5;++tim)
	{
		bool flag=0;
		double X,Y;
		for(int i=0;i<4;++i)
		{
			double xx=x+dx[i]*step,yy=y+dy[i]*step;
			double val=Val(xx,yy);
			if(val<err)
			{
				err=val;
				flag=1;
				X=xx;Y=yy;
			}
		}
		if(flag){x=X;y=Y;}
		else step/=2;
	}
	if(err<1e-6)printf("%.5f %.5f\n",x,y);
	return 0;
}