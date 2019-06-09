#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int min(int a,int b){return a>b?b:a;}
const int N = 333;
const int M = N*N;
const int inf = 0x7fffffff;

struct node
{
	int nxt,to,c,w,from;//w为费用，c为流量，nxt还是前向星
}E[M];

int cnt = 1,point[N];

void ins(int u,int v,int c,int w)
{
//	E[++cnt] = (node){point[u],v,c,w,u};
	E[++cnt].nxt = point[u];
	E[cnt].to = v;
	E[cnt].c = c;
	E[cnt].w = w;
	E[cnt].from = u;
	point[u] = cnt;
//	E[++cnt] = (node){point[v],u,0,-w,v};
	E[++cnt].nxt = point[v];
	E[cnt].to = u;
	E[cnt].c = 0;
	E[cnt].w = -w;
	E[cnt].from = v;
	point[v] = cnt;
}

bool inq[N];
int dist[N],pre[N],q[N];

bool spfa(int s,int t)
{
	int i;
	for( i = 1 ; i <= t ; i++)
		dist[i] = inf;
	int head = 0,tail = 1,u,v,tt;
	dist[s] = 0;inq[s] = true;q[1] =s;
	while(head!=tail)
	{
		++head;
		if(head == N)
			head = 0;
		u = q[head];
		inq[u] = false;
		for( i = point[u]; i ; i =E[i].nxt)
		{
			if(E[i].c&&dist[v=E[i].to]>(tt=dist[u]+E[i].w))
			{
				dist[v] = tt;
				pre[v] = i;
				if(!inq[v])
				{
					inq[v] = true;
					++tail;
					if(tail==N)
						tail = 0;
					q[tail] = v;
				}
			}
		}
	}
	return dist[t]!=inf;
}

int MCMF(int s,int t)
{
	int ret = 0;
	while(spfa(s,t))
	{
		int f = inf,u;
		for( u = t ; u != s ; u = E[pre[u]].from)
		{
			f = min(f,E[pre[u]].c);
		}
		for( u = t ; u != s ; u = E[pre[u]].from)
		{
			E[pre[u]].c-=f;
			E[pre[u]^1].c+=f;
		}
		ret += dist[t]*f;
	}
	return ret;
}

int n,du[N],S,T,ans = 0;

int main()
{
	int i;
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for( i = 1 ; i <= n ; i++)
	{
		int tot,bi,ti;
		scanf("%d",&tot);
		du[i]-=tot;//du[i]记录了点i的入度减去出度的个数
		while(tot--)
		{
			scanf("%d%d",&bi,&ti);
			ins(i,bi,inf,ti);
			++du[bi];//bi的入度计数
			ans+=ti;//ans记录的是所有的边权和
		}
		if(i!=1)
			ins(i,1,inf,0);//可以任意时刻退回到点1，费用为0
	}
	S = n+1 ; T = S+1;
	for( i = 1 ; i <= n ; ++i)
	{
		if(du[i]>0)
		{
			ins(S,i,du[i],0);
		}
		if(du[i]<0)
		{
			ins(i,T,-du[i],0);
		}
	}
	printf("%d\n",MCMF(S,T)+ans);
	return 0;
}
