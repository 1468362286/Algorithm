#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int t,s,x;
	while(~scanf("%d%d%d",&t,&s,&x))
	{
		if(x-t==1)
		{
			printf("NO\n");
			continue;
		}
		if(x<t)
		{
			printf("NO\n");
			continue;
		}
		if((x-t)%s==0||((x-t)-1)%s==0)
		{
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}