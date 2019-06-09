#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int w[15],cnt[4100],sum[4100][105];

void solve()
{
	int n,m,q,i,j,k;
	scanf("%d%d%d",&n,&m,&q);
	for( i = 1 ; i <= n ; i++)
		scanf("%d",&w[i]);
	for( i = 1 ; i <= m ; i++)
	{
		char s[15];
		scanf("%s",s);
		int x=0;
		for( j = 0 ; j < n ;j++)
			if(s[j]=='1')
				x+=1<<(n-j-1);
		cnt[x]++;
	}
	for( i = 0 ; i <(1<<12) ; i++)
	{
		for( j = 0 ; j <(1<<12) ; j++)
		{
			if(!cnt[j])
				continue;
			int x=0;
			for( k = 0 ; k < 12 ; k++)
			{
				if((i&(1<<k))==(j&(1<<k)))
					x+=w[n-k];
				if(x>100)
					break;
			}
			if(x<=100)
				sum[i][x]+=cnt[j];
		}
	}
	while(q--)
	{
		char s[15];int k;
		scanf("%s%d",s,&k);
		int x=0;
		for( i = 0 ; i < n ; i++)
			if(s[i]=='1')
				x+=1<<(n-i-1);
		int ans=0;
		for( i = 0 ; i <= k ; i++)
			ans+=sum[x][i];
		printf("%d\n",ans);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}