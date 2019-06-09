#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct point
{
	double x,y;
}convex[100];

double cross(const point &p1,const point &p2,const point &q1,const point &q2)
{
	return (q2.y-q1.y)*(p2.x-p1.x)-(q2.x-q1.x)*(p2.y-p1.y);
}

bool cmp(const point &a,const point &b)
{
	point origin;
	origin.x = origin.y = 0;
	return cross(origin,b,origin,a)<0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int cnt = 0;
	while(~scanf("%lf%lf",&convex[cnt].x,&convex[cnt].y))
		cnt++;
	sort(convex+1,convex+cnt,cmp);
	for(int i = 0 ; i < cnt ; i++)
	{
		printf("(%.0lf,%.0lf)\n",convex[i].x,convex[i].y);
	}
	return 0;
}