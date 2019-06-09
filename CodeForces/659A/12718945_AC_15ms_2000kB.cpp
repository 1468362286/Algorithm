#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int n,a,t,ans;
	while(~scanf("%d%d%d",&n,&a,&t))
	{
		if(t>=0)
		{
			ans=(a+t)%n;
		}
		else
		{
			ans=(a+t+((-t)/n+1)*n)%n;
		}
		if(ans==0)
			ans=n;
		printf("%d\n",ans);
	}
	return 0;
}