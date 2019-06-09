
#include <stdio.h>
#include <string.h>
const int maxn = 100010;
const int maxm = 200020;
int a[maxn];
int pre_sum[maxn];
int ans[2][maxm];

int main()
{
	//freopen("in.txt","r",stdin);
	int h,i,j;
	while(~scanf("%d",&h))
	{
		memset(pre_sum,0,sizeof(pre_sum));
		int n = 0;
		int flag = 0;
		pre_sum[0]=1;
		for( i = 0 ; i <= h ; i++)
		{
			scanf("%d",a+i);
			if(a[i]>1&&a[i-1]>1&&i>=1)
				flag = 1;
			if(i>0)
			pre_sum[i]+=pre_sum[i-1]+a[i];
		}
		if(!flag)
		{
			printf("perfect\n");
			continue;
		}
		printf("ambiguous\n");
		ans[0][1]=ans[1][1]=0;
		int cnt = 1;
		for( i = 1 ; i <= h ; i++)
		{
			for( j = 0 ; j < a[i] ; j++)
			{
				cnt++;
				ans[0][cnt]=ans[1][cnt]=pre_sum[i-1];
			}
							if(a[i]>1&&a[i-1]>1)
			{
				ans[0][cnt]--;
			}
		}
		for( i = 0 ; i < 2 ; i++)
		{
			for( j = 1 ; j <= pre_sum[h] ; j++)
			{
				if(j==1)
					printf("%d",ans[i][j]);
				else
					printf(" %d",ans[i][j]);
			}
			printf("\n");
		}
	//	printf("\n");
	}
	return 0; 
}


