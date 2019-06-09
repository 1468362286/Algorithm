#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef _int64 ll;
ll k;
int n,m;
ll a[25][25];
map<ll,ll>mp[25];
int dir[2][2]={1,0,0,1};
ll ans;
int maxi;
void dfs(int x,int y,ll sum,int step)
{
	if(step>maxi)maxi=step;
	if(x==n-1&&y==m-1)
	{
		if(sum==k)
			ans++;
		return;
	}
	for(int i = 0 ; i < 2 ; i++)
	{
		int dx = x+dir[i][0];
		int dy = y+dir[i][1];
		if(dx>=0&&dx<n&&dy>=0&&dy<m)
		{
			dfs(dx,dy,a[dx][dy]^sum,step+1);
		}
	}
}

void dfs_down(int x,int y,ll maxn)
{
	if(x+y==(n+m-1)/2)
	{
		mp[x][maxn]++;
		return;
	}
	if(x<n-1)
		dfs_down(x+1,y,maxn^a[x+1][y]);
	if(y<m-1)
		dfs_down(x,y+1,maxn^a[x][y+1]);
}

void dfs_up(int x,int y,ll maxn)
{
	if(x+y==(n+m-1)/2)
	{
		if(mp[x].find(maxn^k^a[x][y])!=mp[x].end())
		{
			ans+=mp[x][maxn^k^a[x][y]];
		}
		return;
	}
	if(x>0)dfs_up(x-1,y,maxn^a[x-1][y]);
	if(y>0)dfs_up(x,y-1,maxn^a[x][y-1]);
}
int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%d%d%I64d",&n,&m,&k))
	{
		for( i = 0 ; i < n ; i++)
			for( j = 0 ; j < m ; j++)
			{
				scanf("%I64d",&a[i][j]);
			}
		ans=0;
//		dfs(0,0,a[0][0],0);
		dfs_down(0,0,a[0][0]);
		dfs_up(n-1,m-1,a[n-1][m-1]);
		printf("%I64d\n",ans);
	}
	return 0;
}
