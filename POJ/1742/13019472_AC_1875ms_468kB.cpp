#include <iostream>
#include <string.h>
using namespace std;

const int MAXN=150;
int w[MAXN],c[MAXN];
int n,m;
bool dp[100000+10], queue[100000+10];

int solve_dp()
{
	int i,v,d;
	memset(dp,0,sizeof(dp));
	memset(queue,0,sizeof(queue));
	dp[0]=true;

	for( i = 0 ; i < n ; i++)
	{
		if(c[i]==1)
		{
			for( v = m ; v >= w[i] ; v--)
			{
				if(!dp[v]&&dp[v-w[i]])
					dp[v]=1;
			}
		}
		else if(c[i]*w[i]>=m)
		{
			for( v = w[i] ; v <= m ; v++)
			{
				if(!dp[v]&&dp[v-w[i]])
					dp[v]=1;
			}
		}
		else
		{
			for( d = 0 ; d < w[i] ; d++)
			{
				int sum=0,st=0,ed=-1;
				for( v = d ; v <= m ; v+=w[i])
				{
					if(ed-st==c[i])
					{
						sum-=queue[st++];
					}
					queue[++ed]=dp[v];
					sum+=dp[v];
					if(!dp[v]&&sum)
						dp[v]=1;
				}
			}
		}
	}
	int res=0;
	for( i = 1 ; i <= m ; i++)
		res+=dp[i];
	return res;
}

int main()
{
	int i;
//	freopen("in.txt","r",stdin);
	while(cin>>n>>m&&n!=0)
	{
		for( i = 0 ; i < n ; i++)
			scanf("%d",&w[i]);
		for( i = 0 ; i < n ; i++)
			scanf("%d",&c[i]);
		cout<<solve_dp()<<endl;
	}
	return 0;
}