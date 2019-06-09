#include <stdio.h>
#include <string.h>
double min(double a,double b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int h,m,H,D,C,N;
	double ans,t;
	while(~scanf("%d%d",&h,&m))
	{
		scanf("%d%d%d%d",&H,&D,&C,&N);
		if(h>=20)
		{
			if(H%N==0)
				ans = (C*0.8)*(H/N);
			else
				ans = (C*0.8)*(H/N+1);
		}
		else
		{
			int tmp = ((19-h)*60+(60-m))*D;
			if((H+tmp)%N==0)
				ans = (C*0.8)*((H+tmp)/N);
			else
				ans = (C*0.8)*((H+tmp)/N+1);
			if(H%N==0)
				t = C*(H/N);
			else
				t = C*(H/N+1);
			ans=min(ans,t);
		}
		printf("%.4lf\n",ans);
	}
	return 0;
}