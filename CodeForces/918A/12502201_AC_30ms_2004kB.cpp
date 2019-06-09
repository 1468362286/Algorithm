#include <stdio.h>
#include <string.h>
const int maxn = 17;
int f[maxn];
int vist[2000];
void init()
{
	memset(vist,0,sizeof(vist));
	f[0]=1,f[1]=1;
	vist[f[0]]=vist[f[1]]=1;
	for(int i = 2 ; i < maxn ; i++)
	{
		f[i]=f[i-1]+f[i-2];
		vist[f[i]]=1;
	}
}
int main()
{
	int n;
	init();
	while(~scanf("%d",&n))
	{
		for(int i = 1 ; i <= n ; i++)
			printf("%c",vist[i]?'O':'o');
		printf("\n");
	}
	return 0;
}