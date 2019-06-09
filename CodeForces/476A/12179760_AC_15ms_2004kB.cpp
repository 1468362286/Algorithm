#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,ans;
	while(~scanf("%d%d",&n,&m))
	{
		int flag = 0;
		for(int i = n/2 ; i <= n; i++)
		{
			if(i%m==0&&1.0*n/i<=2.0)
			{
				flag = 1;
				ans = i;
				break;
			}
		}
		if(flag)
		printf("%d\n",ans);
		else
			printf("-1\n");
	}
	return 0;
}