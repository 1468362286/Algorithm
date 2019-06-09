#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		printf("%d\n",n+n/2);
		for( i = 2 ; i <= n ; i+=2)
		{
			printf("%d ",i);
		}
		for( i = 1 ; i <= n ; i+=2)
		{
			printf("%d ",i);
		}
		for( i = 2 ; i <= n ; i+=2)
		{
			if(i==n||i==n-1)
				printf("%d\n",i);
			else
				printf("%d ",i);
		}
	} 
	return 0;
}