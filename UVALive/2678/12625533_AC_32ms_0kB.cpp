#include <stdio.h>
#include <string.h>
const int maxn = 100010;
int a[maxn];
int pre_sum[maxn];
int min(int a,int b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,s,l,r,i,T;
//	scanf("%d",&T);
	while(~scanf("%d%d",&n,&s))
	{
		int flag=0;
		int mina=n+1;
		memset(pre_sum,0,sizeof(pre_sum));
		for( i = 1 ; i <= n; i++)
		{
			scanf("%d",&a[i]),pre_sum[i]=pre_sum[i-1]+a[i];
		}
		l=1,r=1;
		while(1)
		{
			if(r>n&&pre_sum[r]-pre_sum[l-1]<s)
				break;
			if(pre_sum[r]-pre_sum[l-1]>=s)
			{
				mina=min(mina,r-l);
				l++;
			}
			else
			{
				r++;
			}
		}
		if(mina<n+1)
		printf("%d\n",mina+1);
		else
			printf("0\n");
	}
	return 0;
}