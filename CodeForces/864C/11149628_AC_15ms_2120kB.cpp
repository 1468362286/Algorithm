#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int a,b,f,k;
	while(~scanf("%d%d%d%d",&a,&b,&f,&k))
	{
		if((b<f)||(b<a-f))
		{
			printf("-1\n");
			continue;
		}
		else if(k==2&&b<2*(a-f))
		{
			printf("-1\n");
			continue;
		}
		else if(k>2&&b<a)
		{
			printf("-1\n");
			continue;
		}
		int bag = b;
		int flag1=1,flag2=0,count=0;
		for(int i = 1 ; i <= k ; i++)
		{
			if(flag1)
			{
				bag-=f;
			//	printf("%d\n",2*(a-f));
				if((i!=k&&bag<2*(a-f))||(i==k&&bag<a-f))
				{
					bag = b;
					count++;
				}
				bag-=(a-f);
				flag1=0;
				flag2=1;
			}
			else if(flag2)
			{
				bag-=(a-f);
				if((i!=k&&bag<2*f)||(i==k&&bag<f))
				{
					bag = b;
					count++;
				}
				bag-=f;
				flag2=0;
				flag1=1;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}