#include <stdio.h>
#include <string.h>
const int maxn = 200010;
int a[maxn];
int last[maxn];
int num[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		for( i = 1 ; i <= n ; i++)
			scanf("%d",a+i);
		int ans = 1;
		for( i = 1 ; i <= n ; i++)
		{
			int now = a[i];
			if(last[num[now]]==a[i])
			{
				last[num[now]]=i;
				num[i]=num[now];
			}
			else
			{
				num[i]=++ans;
				last[num[i]] = i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}