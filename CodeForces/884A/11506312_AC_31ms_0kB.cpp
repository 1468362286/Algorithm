#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int n,t,x,ans;
	while(~scanf("%d%d",&n,&t))
	{
		int sum = 0;
		int flag = 1;
		for(int i = 0 ; i < n; i++)
		{
			scanf("%d",&x);
			sum+=86400-x;
			if(sum>=t&&flag)
			{
				ans=i+1;
				flag = 0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}