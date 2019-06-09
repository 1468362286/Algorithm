#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int maxn = 1000010;
const int maxm = 1000010;
const int inf=0x3f3f3f3f;
int max(int a,int b){return a>b?a:b;}
struct Edge
{
	int u,v,w;
	Edge(){};
	Edge(int u,int v,int w):u(u),v(v),w(w){};
}E[maxm];
int cnt;
int head[maxn],nxt[maxn];
int dis[maxn];
bool vist[maxn];
int visitCount[maxn];
int n,ml,md;

void addedge(int u,int v,int w)
{
	E[cnt]=Edge(u,v,w);
	nxt[cnt]=head[u];
	head[u]=cnt++;
}

bool spfa(int s,int t)
{
	int i;
	queue<int> p;
	while(!p.empty())p.pop();
	for( i = 1 ; i <= n ; i++)
	{
		dis[i]=inf;
		vist[i]=false;
		visitCount[i]=0;
	}
	p.push(s);
	vist[s]=true;
	dis[s]=0;
	while(!p.empty())
	{
		int tmp=p.front();
		p.pop();
		vist[tmp]=false;
		if(visitCount[tmp]++>n)
			return true;
		for( i = head[tmp] ; ~i ; i = nxt[i])
		{
			int u = E[i].u;
			int v = E[i].v;
			int w = E[i].w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				if(!vist[v])
				{
					vist[v]=true;
					p.push(v);
				}
			}
		}
	}
	return false;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,u,v,w;
	while(~scanf("%d%d%d",&n,&ml,&md))
	{
		memset(head,-1,sizeof(head));
		memset(nxt,0,sizeof(nxt));
		cnt=0;
		for( i = 0 ; i < ml ; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
		}
		for( i = 0 ; i < md ; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(v,u,-w);
		}
		if(spfa(1,n))
		{
			printf("-1\n");
		}
		else
		{
			if(dis[n]==inf)
				printf("-2\n");
			else
				printf("%d\n",dis[n]);
		}		
	}
	return 0;
}


/*耗时:63ms,orz 一次过，我都不知道发生了什么*/