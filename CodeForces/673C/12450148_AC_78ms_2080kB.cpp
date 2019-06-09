#include <stdio.h>
#include <string.h>
const int N = 5010;
int hash[N],vist[N],G[N],a[N];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,cnt,i,j,k,ansi;
	while(~scanf("%d",&n))
	{
		for( i = 1 ; i <= n ; i++)
			scanf("%d",a+i);
		memset(G,0,sizeof(G));
		for( i = 1 ; i <= n ; i++)
		{
			int maxi=0;
			int ansi = n+1;
			memset(hash,0,sizeof(hash));
			for( j = i ; j <= n ; j++)
			{

				hash[a[j]]++;
				if(maxi<hash[a[j]]||(maxi==hash[a[j]]&&ansi>a[j]))
				{
					maxi=hash[a[j]];
					ansi=a[j];
				}		
				G[ansi]++;
			}
			
		}
		for( i = 1 ; i <= n ; i++)
			printf("%d%s",G[i],i==n?"\n":" ");
	}
	return 0;
}
