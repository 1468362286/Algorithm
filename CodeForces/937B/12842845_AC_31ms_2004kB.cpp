#include <stdio.h>
#include <math.h>
int p,y;
bool prime(int x)
{
	for(int i = 2 ; i*i<=x&&i<=p; i++)
		if(x%i==0)
			return false;
	return true;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	while(~scanf("%d%d",&p,&y))
	{
		int flag=0;
		for( i = y ; i > p ; i--)
		{
			if(prime(i))
			{
				printf("%d\n",i);
				flag=1;
				break;
			}
		}
		if(!flag)
			printf("-1\n");
	}
	return 0;
}