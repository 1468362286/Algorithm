#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		if(c==0)
		{
			if(a==b)
				printf("YES\n");
			else
				printf("NO\n");
			continue;
		}
		if(((b-a)%c)==0&&((b-a)/c>=0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}