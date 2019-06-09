#include <stdio.h>
#include <math.h>
const double pi = acos(-1);
int main()
{
	//freopen("in.txt","r",stdin);
	double d,h,v,e;
	while(~scanf("%lf%lf%lf%lf",&d,&h,&v,&e))
	{
		double s = (d*d)/4*pi;
		double wator=s*e;
		if(v<wator)
			printf("NO\n");
		else
		{
			printf("YES\n%.12lf\n",(s*h)/(v-wator));
		}
	}
	return 0;
}