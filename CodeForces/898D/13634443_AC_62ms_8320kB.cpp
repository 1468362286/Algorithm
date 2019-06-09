#include <stdio.h>
#include <string.h>
const int maxn = 200010;

int pre_sum[1000010];
bool vist[1000010];

int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,k,i,x;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		int maxi = 0;
		memset(vist,false,sizeof(vist));
		memset(pre_sum,0,sizeof(pre_sum));
		for( i = 0 ; i < n ; i++)
			scanf("%d",&x),vist[x]=true,maxi=max(x,maxi);
		int cnt = 0;
		int ans = 0;
		if(maxi<m)
		{
			printf("%d\n",n-k+1);
			continue;
		}
		for( i = 0 ; i <= maxi ; i++)
		{
			if(vist[i])
				cnt++;
			pre_sum[i] = cnt;
			
			
			//	ans = max(ans,pre_sum[i]-pre_sum[i-m]);
				if(vist[i-m]&&i>=m)
					cnt--;
				if(cnt>=k)
				{
					vist[i] = 0;
					ans++,cnt--;
				}
			
		}
		printf("%d\n",ans);
	}
	return 0;
}