#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <queue>
using namespace std;
typedef _int64 ll;
ll ST;
const int maxn = 100010;
int V[maxn],T;

priority_queue<ll> que;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j;
	while(~scanf("%d",&n))
	{
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",&V[i]);
		}
		/*
		for( i = 1;  i <= n ; i++)
			scanf("%d",&T[i]);
		memset(ans,0,sizeof(ans));
		for( i = 1 ; i <= n ; i++)
		{
			for( j = 1 ; j <= i ; j++)
			{
				if(V[j]>=T[i])
				{
					V[j]-=T[i];
					ans[i]+=T[i];
				}
				else 
				{
					ans[i]+=V[j];
					V[j]=0;
				}
			}
		}
		for( i = 1 ; i <= n ; i++)
		{
			printf("%d%s",ans[i],i==n?"\n":" ");
		}
		*/
		ST=0;
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",&T);
			que.push(-V[i]-ST);
			ll ans=0;
			while(!que.empty() && (que.top()>=(-ST-T)))
			{
				ans-=que.top()+ST;
				que.pop();
			}
			ST+=T;
			ans+=T*que.size();
			printf("%I64d ",ans);
		}
	}
	return 0;
}