#include <stdio.h>
int min(int a,int b){return a>b?b:a;}
int main()
{
	int d1,d2,d3;
	while(~scanf("%d%d%d",&d1,&d2,&d3))
	{
		int ans = min((d2+d3)*2,(d1+d3)*2);
		printf("%d\n",min(d1+d2+d3,min((d1+d2)*2,ans)));
	}
	return 0;
}