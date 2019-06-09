#include <stdio.h>
const int maxn = 2010;
int s[maxn],d[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	int tmp;
	while(~scanf("%d",&n))
	{
		tmp = 0;
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d%d",&s[i],&d[i]);
			if(i==1)
				tmp = s[i];
			else
			{
				int sum = s[i];
				while(sum<=tmp)
				{
					sum+=d[i];
				}
				tmp = sum;
			}
		}
		printf("%d\n",tmp);
	}
	return 0;
}
