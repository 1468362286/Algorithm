#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i;
	while(~scanf("%d%d",&n,&k))
	{
		int x=0,y=0;
		int temp = n;
		while(n%5==0&&x<k)
		{
			n/=5;
			x++;
		}
		while(n%2==0&&y<k)
		{
			n/=2;
			y++;
		}
		printf("%d",n);
		for( i = 0 ; i < k ; i++)
			printf("0");
		printf("\n");
	}
	return 0;
}