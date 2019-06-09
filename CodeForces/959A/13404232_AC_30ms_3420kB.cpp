#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n%2==0)
			printf("Mahmoud\n");
		else
			printf("Ehab\n");
	}
	return 0;
}