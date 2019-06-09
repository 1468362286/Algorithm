#include <stdio.h>
#include <string.h>

int n;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
struct Edge
{
	int v,next;
}edge[10005];
int edgeNum;
int head[105],visit[105];

int componentMap[105];
int componentNum;
int dfn[105];
int low[105];

int stack[105];
int stackSize;

int inDegree[105];
int outDegree[105];
void addedge(int u,int v)
{
	edge[edgeNum].v=v;
	edge[edgeNum].next=head[u];
	head[u]=edgeNum++;
}

void dfs(int u,int step)
{
	dfn[u]=step;
	low[u]=step;
	visit[u]=1;
	stack[++stackSize]=u;
	for(int i = head[u] ; i != -1 ; i = edge[i].next)
	{
		int v=edge[i].v;
		if(visit[v]==0)
			dfs(v,step+1);
		if(visit[v]==1)
			low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u])
	{
		componentNum++;
		int k;
		do
		{
			k=stack[stackSize--];
			componentMap[k]=componentNum;
			visit[k]=2;
		}while(k!=u);
	}
}

void tarjan()
{
	componentNum=0;
	stackSize=0;
	memset(visit,0,sizeof(visit));
	for(int u = 1 ; u <= n ; u++)
	{
		if(visit[u]==0)
			dfs(u,1);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int u,i;
	while(~scanf("%d",&n))
	{
		edgeNum=0;
		memset(head,-1,sizeof(head));
		for( i = 1 ; i <= n ; i++)
		{
			while(1)
			{
				scanf("%d",&u);
				if(u==0)
					break;
				else
					addedge(i,u);
			}
	
		}
		tarjan();
		memset(inDegree,0,sizeof(inDegree));
		memset(outDegree,0,sizeof(outDegree));

		for( u = 1 ; u <= n ; u++)
		{
			for( i = head[u] ; i!=-1 ; i = edge[i].next)
			{
				int v=edge[i].v;
				if(componentMap[u]!=componentMap[v])
				{
					outDegree[componentMap[u]]++;
					inDegree[componentMap[v]]++;
				}
			}
		}
		int leafNum,rootNum;
		leafNum=rootNum=0;
		for( u = 1 ; u <= componentNum ; u++)
		{
			if(outDegree[u]==0)
				leafNum++;
			if(inDegree[u]==0)
				rootNum++;
		}

		printf("%d\n",rootNum);
		if(componentNum==1)
			printf("0\n");
		else
			printf("%d\n",max(rootNum,leafNum));
	}
	return 0;
}