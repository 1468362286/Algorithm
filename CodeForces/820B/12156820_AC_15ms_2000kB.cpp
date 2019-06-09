#include <stdio.h>
#include <math.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int n,ans;
	double a,tmp;
	while(~scanf("%d%lf",&n,&a))
	{

		double mina = 0x3f3f3f3f;
		double p = 180*(n-2);
		p = p/n;
		p = p/(n-2);
		for(int i = 0 ; i < n-2 ; i++)
		{
			if(i==555)
				int flag = 1;
			double gg = p*(i+1);
			if(gg>a)
				tmp = gg-a;
			else
				tmp = a-gg;
			if(tmp<mina)
			{
				mina = tmp;
				ans = i+1;
			}
		}
		printf("2 1 %d\n",2+ans);
	}
	return 0;
}