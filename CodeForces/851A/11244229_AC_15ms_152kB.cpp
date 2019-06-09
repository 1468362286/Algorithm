#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	_int64 n,k,t;
	while(~scanf("%I64d%I64d%I64d",&n,&k,&t))
	{
		if(t<=k)
			printf("%d\n",t);
		else if(t>k&&t<=n)
			printf("%d\n",k);
		else if(t>n)
		{
			printf("%I64d\n",n+k-t);
		}
	}
}