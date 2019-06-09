#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
typedef _int64 ll;
const int maxn = 150010;
struct Node
{
	ll vertices;
	ll edges;
	Node()
	{
		vertices=0;
		edges=0;
	}
}node[maxn];
int n,m;

int fa[maxn];
vector<int> E[maxn];

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

void unix(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx!=fy)
	{
		fa[fx]=fy;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int i,x,y;
	while(~scanf("%d%d",&n,&m))
	{
		for( i = 1 ; i <= n ; i++)
			fa[i] = i;
		for( i = 0 ; i < m ; i++)
		{
			scanf("%d%d",&x,&y);
			unix(x,y);
			E[x].push_back(y);
		}
		for( i = 1 ; i <= n ; i++)
			find(i);
		for( i = 1 ; i <= n ; i++)
		{
			node[fa[i]].vertices++;
			ll tmp = E[i].size();
			node[fa[i]].edges+=tmp;
		}
		int flag = 0;
		for( i = 1 ; i <= n ; i++)
		{
			if(node[i].vertices!=0||node[i].edges!=0)
			{
			//	printf("%I64d %I64d\n",node[i].vertices,node[i].edges);
				ll pp = (node[i].vertices*(node[i].vertices-1))/2;
				ll gg = node[i].edges;
				if(pp!=gg)
				{
			//		printf("%d\n",i);
			//		printf("%I64d %I64d\n",node[i].vertices,node[i].edges);
					flag = 1;
					break;
				}
			}
		}
		if(flag)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}