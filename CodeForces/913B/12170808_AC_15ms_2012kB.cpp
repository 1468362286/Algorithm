#include <stdio.h>
#include <string.h>
const int maxn = 4000;
int fa[1010];
int hash[1010];
int vist[1010];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		memset(hash,0,sizeof(hash));
		memset(vist,0,sizeof(vist));
		for( i = 2 ; i <= n ; i++)
		{
			scanf("%d",&fa[i]);
			hash[fa[i]]++;
			vist[fa[i]] = 1;
		}
		for( i = 1 ; i <= n ; i++)
		{
			if(vist[i])
			{
				if(vist[fa[i]])
				{
					hash[fa[i]]--;
				}
			}
		}
		int flag = 0;
		for( i = 1 ; i <= n ; i++)
		{
			if(vist[i])
			{
				if(hash[i]<3)
				{
					flag = 1;
					break;
				}
			}
		}
		printf("%s\n",flag?"No":"Yes");
	}
	return 0;
}