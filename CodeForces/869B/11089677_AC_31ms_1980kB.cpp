#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	_int64 a,b;
	while(~scanf("%I64d%I64d",&a,&b))
	{
		if(b-a>10)
		{
			printf("0\n");
			continue;
		}
		int ans = 1;
		for(_int64 i = a+1 ; i <= b ; i++)
		{
			ans*=i%10;
		}
		printf("%I64d\n",ans%10);
	}
	return 0;
}