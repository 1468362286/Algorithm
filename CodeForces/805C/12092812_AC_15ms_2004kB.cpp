#include <stdio.h>

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n%2==0)
		{
			printf("%d\n",n/2-1);
		}
		else
		{
			printf("%d\n",n/2);
		}
	}
	return 0;
}