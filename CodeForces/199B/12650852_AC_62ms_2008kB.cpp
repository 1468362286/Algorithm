#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
double tmp;
double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int fun(double a,double b,double c)
{
	if(a-c>=tmp||b-a>=tmp||a+c<=tmp)
		return 1;
	return 0;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int ans;
	double x1,y1,r1,R1,x2,y2,r2,R2;
	while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&R1,&x2,&y2,&r2,&R2))
	{
		tmp = dis(x1,y1,x2,y2);
		ans=fun(r1,r2,R2)+fun(R1,r2,R2)+fun(r2,r1,R1)+fun(R2,r1,R1);
		printf("%d\n",ans);
	}
	return 0;
}