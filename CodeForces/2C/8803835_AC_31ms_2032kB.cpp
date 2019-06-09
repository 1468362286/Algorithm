#include <iostream>
#include <string>
#include <math.h>
using namespace std;
const int INF = 1e+9;
const double delta = 0.5;
double angle[3];
struct Node 
{
	double x;
	double y;
	double r;
}node[3];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
double dis(double x,double y,double xx,double yy)
{
	double ans = sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
	return ans;
}
double calc(double x,double y)
{
	int i;
	for( i = 0 ; i < 3 ; i++)
	{
		angle[i] = dis(x,y,node[i].x,node[i].y)/node[i].r; 
	}
	double ans = 0;
	for( i = 0 ; i < 3 ; i++)
	{
		ans+=(angle[i]-angle[(i+1)%3])*(angle[i]-angle[(i+1)%3]);
	}
	return ans;
}
int main()
{
	int i,tim,flag;
	double x = 0,y = 0;
	for( i = 0 ; i < 3 ; i++)
	{
		scanf("%lf%lf%lf",&node[i].x,&node[i].y,&node[i].r);
		x+=node[i].x/3;
		y+=node[i].y/3;
	}
	double t = 1;
	double x1,y1,X,Y;
	double h1,h;
	h = calc(x,y);
	//double zz = calc(30,0);
	for( tim = 0 ; tim < 1e+5 ; tim++)
	{
		flag = 0;
		for( i = 0 ; i < 4; i++)
		{
			x1 = x + dir[i][0]*t;
			y1 = y + dir[i][1]*t;
			h1 = calc(x1,y1);
			if(h1<h)
			{
				h = h1;
				X = x1;
				Y = y1;
				flag = 1;
			}
		}
		if(!flag)
		{
			t*=delta;
		}
		else
		{
			x = X;
			y = Y;
		}
	}
	if(h<1e-6)
	printf("%.5lf %.5lf\n",x,y);
	return 0;
}