#include <stdio.h>
#include <string.h>
int hash[110],a[110];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i;
	while(~scanf("%d%d",&n,&k))
	{
		memset(hash,0,sizeof(hash));
		int count = 0;
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",&a[i]);
			hash[a[i]] = 1;
		}
		for( i = 0 ;  i < k ; i++)
		{
			if(hash[i]==0)
				count++;
		}
		if(hash[k])
			count++;
		printf("%d\n",count);
	}
	return 0;
}