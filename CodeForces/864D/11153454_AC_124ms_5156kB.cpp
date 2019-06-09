#include <stdio.h>
#include <string.h>
const int maxn = 200010;
int a[maxn],b[maxn],vist[maxn];
int  hash[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,cnt;
	while(~scanf("%d",&n))
	{
		memset(hash,0,sizeof(hash));
		memset(vist,0,sizeof(vist));
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",&a[i]);
			hash[a[i]]++;
		}
		cnt = 0;
		for( i = 1 ; i <= n ; i++)
		{
			if(!hash[i])
				b[cnt++] = i;
		}
//		int ans = n-cnt;
		printf("%d\n",cnt);
		cnt = 0;
		if(hash[a[0]]==1)
		{
			if(!vist[a[0]])
			printf("%d",a[0]);
			else
				printf("%d",b[cnt++]);
		}
		else
		{
			if(a[0]>b[cnt])
			{
				printf("%d",b[cnt]);
				vist[b[cnt]] =1;
				cnt++;
				hash[a[0]]--;
			}
			else
			{
				printf("%d",a[0]);
				hash[a[0]]--;
				vist[a[0]]=1;
			}
		}
		for( i = 1 ; i < n ; i++)
		{
			if(hash[a[i]]==1)
			{
				if(!vist[a[i]])
				printf(" %d",a[i]);
				else
					printf(" %d",b[cnt++]);
			}
			else
			{
				if(a[i]>b[cnt]||vist[a[i]])
				{
					printf(" %d",b[cnt]);
					vist[b[cnt]]=1;
					hash[a[i]]--;
					cnt++;
				}
				else if(!vist[a[i]])
				{
					printf(" %d",a[i]);
					hash[a[i]]--;
					vist[a[i]]=1;
				}
			}
		}
		printf("\n");
	}
	return 0;
}