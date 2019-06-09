#include <stdio.h>

int main()
{
	int l,r;
	while(~scanf("%d%d",&l,&r))
	{
		if(r-l>=1)
		printf("2\n");
		else if(r==l)
			printf("%d\n",r);
	}
	return 0;
}