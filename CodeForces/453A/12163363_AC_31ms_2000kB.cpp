#include <stdio.h>
#include <math.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		double ans = 0;
		double now=0,pre=0;
		for(int i= 1 ; i <= n ; i++)
		{
			now = pow((double)i/n,m);
			ans+=(now-pre)*i;
			pre = now;
		}
		printf("%.4lf\n",ans);
	}
	return 0;
}