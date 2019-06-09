#include <stdio.h>
typedef _int64 ll;
const int inf=0x7fffffff;
ll f[1000];
void init()
{
	f[0]=0;
	f[1]=1;
	for(int i = 2 ; ; i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>inf)
		{
			break;
		}
	}
}
int main()
{
	int n,ans;
	init();
	while(~scanf("%d",&n))
	{
		if(n==2)
		{
			printf("0 1 1\n");
			continue;
		}
		if(n==1)
		{
			printf("0 0 1\n");
			continue;
		}
		if(n==0)
		{
			printf("0 0 0\n");
			continue;
		}
		for(int i = 0 ;  ; i++)
			if(f[i]==n)
			{
				ans = i;
				break;
			}
		printf("%I64d %I64d %I64d\n",f[ans-1],f[ans-3],f[ans-4]);
	}
	return 0;
}