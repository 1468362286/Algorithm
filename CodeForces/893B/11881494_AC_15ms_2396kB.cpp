#include <stdio.h>
#include <string.h>
const int maxn = 100010;
int h[maxn];
void init()
{
	memset(h,0,sizeof(h));
	int tmp;
	for(int i = 1 ;  ; i++)
	{
		tmp = ((1<<i)-1)*(1<<(i-1));
		if(tmp>maxn)
			break;
		h[tmp] = 1;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	init();
	int n,i,ans;
	while(~scanf("%d",&n))
	{
		for( i = n ; i >= 0 ; i--)
		{
			if(h[i])
			{
				if(n%i==0)
				{
					ans = i;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
