#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int T,n,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n%4==0)
			ans = n/4;
		else if(n%4==1)
		{
			if(n/4>=2)
				ans=n/4-1;
			else
				ans=-1;
		}
		else if(n%4==2)
		{
			if(n/4>=1)
				ans=n/4;
			else
				ans=-1;
		}
		else if(n%4==3)
		{
			if(n/4>=3)
				ans=n/4-1;
			else
				ans=-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}