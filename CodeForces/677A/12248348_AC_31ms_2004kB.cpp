#include <stdio.h>


int main()
{
	int n,h,x;
	while(~scanf("%d%d",&n,&h))
	{
		int cnt = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			scanf("%d",&x);
			if(x>h)
				cnt++;
		}
		printf("%d\n",n-cnt+2*cnt);
	}
	return 0;
}