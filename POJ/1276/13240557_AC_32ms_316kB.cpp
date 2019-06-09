#include <cstdio>
#include <cstring>
const int maxn = 100005;
int cash,n,a[15],w[15];
bool dp[maxn],q[maxn];

void zero_one_package(int i)
{
	for(int j = cash ; j >= w[i] ; j--)
	{
		dp[j]=dp[j]||dp[j-w[i]];
	}
}

void complete_package(int i)
{
	for(int j = w[i] ; j <= cash ; j++)
	{
		dp[j]=dp[j]||dp[j-w[i]];
	}
}

void multiple_package(int i)
{
	for(int r = 0 ; r < w[i] ; r++)
	{
		int front = 0 , rear=0 , sum = 0;
		for(int j = r ;  j<=cash ; j+=w[i])
		{
			q[rear++]=dp[j];
			sum+=dp[j];
			if(rear-front>a[i]+1)
				sum-=q[front++];
			dp[j]=dp[j]||sum;
		}
	}
}

int solve()
{
	int i;
	for( i = 1;  i <= n ; i++)
	{
		if(a[i]==1)
			zero_one_package(i);
		else if((a[i]+1)*w[i]>cash)
			complete_package(i);
		else
			multiple_package(i);
	}
	for( i = cash ; i>=0 ; i--)
	{
		if(dp[i])
			return i;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	while(~scanf("%d%d",&cash,&n))
	{
		for(int i = 1 ; i <= n ; i++)
			scanf("%d%d",a+i,w+i);
		memset(dp,0,cash+1);
		dp[0]=true;
		printf("%d\n",solve());
	}
	return 0;
}