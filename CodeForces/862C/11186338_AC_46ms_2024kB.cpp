#include <stdio.h>
int a=1<<17;
int b=1<<18;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,x;
	while(~scanf("%d%d",&n,&x))
	{
		if(n==1)
		{
			printf("YES\n%d\n",x);
		}
		if(n==2)
		{
			if(x==0)
				printf("NO\n");
			else
				printf("YES\n0 %d\n",x);
		}
		if(n>2)
		{
			printf("YES\n");
			int sum = 0;
			for(int i = 1 ; i <= n-3 ; i++)
			{
				printf("%d ",i);
				sum^=i;
			}
			printf("%d %d %d\n",a,b,a^b^sum^x);
		}
	}
	return 0;
}