#include <stdio.h>

int main()
{
	int n,k;
	while(~scanf("%d",&n))
	{
		for(int i = 1 ; i <=26 ; i++)
		{
			k = 1;
			while(k*(k+1)/2<=n)
			{
				k++;
			}
			n-=k*(k-1)/2;
			for(int j = 1 ; j <= k ; j++)
			{
				printf("%c",'a'+i-1);
			}
		}
		printf("\n");
	}
	return 0;
}