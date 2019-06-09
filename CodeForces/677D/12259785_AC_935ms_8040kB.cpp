#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 300+10;
const int INF = 0x7f7f7f7f;
int dp[maxn][maxn],vis[maxn][maxn],cnt[maxn*maxn],cn[maxn*maxn];
int min(int a,int b){return a>b?b:a;}
struct Poi
{
	int x,y,p;
	Poi(){};
	Poi(int x,int y,int p):x(x),y(y),p(p){};
	bool operator<(const Poi &a)const
	{
		return p>a.p;
	}
}poi[maxn*maxn];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,m,p,l;
int cmp(const Poi &a,const Poi &b)
{
	return a.p<b.p;
}

int dis(int a,int b){return abs(poi[a].x-poi[b].x)+abs(poi[a].y-poi[b].y);}

void bfs(int ti)
{
	int x,y,i,j;
	memset(vis,INF,sizeof(vis));
	int tcnt=0,len=n*m;
	queue<Poi> pq;
	for( i = cn[ti-1]-cnt[ti-1] ; i < cn[ti-1] ; i++)
	{
		x=poi[i].x;y=poi[i].y;
		pq.push(Poi(x,y,dp[y][x]));
	}
	while(!pq.empty())
	{
		Poi tp = pq.front();pq.pop();
		for( i = 0 ; i < 4 ; ++i)
		{
			int tx=tp.x+dx[i],ty=tp.y+dy[i];
			if(ty>=1&&tx>=1&&ty<=n&&tx<=m&&vis[ty][tx]>tp.p+1)
			{
				vis[ty][tx] = tp.p+1;
				tcnt++;
				pq.push(Poi(tx,ty,tp.p+1));
			}
		}
	}
	for( j = cn[ti-1] ; j < cn[ti] ; j++)
	{
		x = poi[j].x;y=poi[j].y;
		dp[y][x] = vis[y][x];
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	l=0;
	poi[l++]=Poi(1,1,0);
	cnt[0]=1;
	memset(dp,INF,sizeof(dp));
	int x,y,tx,ty,i,j,z,t;
	while(~scanf("%d%d%d",&n,&m,&p))
	{
		for( i = 1 ; i <= n ; i++)
			for( j = 1 ; j <= m ; j++)
			{
				scanf("%d",&t);
				cnt[t]++;
				poi[l++]=Poi(j,i,t);
			}
		sort(poi,poi+l,cmp);
		cn[0]=1;
		for( i = 1 ; i <= p ; i++)
			cn[i]=cn[i-1]+cnt[i];
		for( i = cn[0] ; i < cn[1] ; ++i)
		{
			dp[poi[i].y][poi[i].x]=dis(0,i);
		}
		for( i = 2 ; i <= p ; i++)
		{
			if(cnt[i]*cnt[i-1]>=n*m)
				bfs(i);
			else
			{
				for( j = cn[i-1] ; j < cn[i] ; j++)
				{
					y=poi[j].y;x=poi[j].x;
					for( z = cn[i-1]-cnt[i-1] ; z < cn[i-1] ; ++z)
					{
						ty=poi[z].y;tx=poi[z].x;
						dp[y][x]=min(dp[y][x],dp[ty][tx]+dis(j,z));
					}
				}
			}
		}
		printf("%d\n",dp[poi[l-1].y][poi[l-1].x]);
	}
	return 0;
}