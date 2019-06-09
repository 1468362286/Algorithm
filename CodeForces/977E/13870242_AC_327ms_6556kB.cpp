#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
int n,m;
int c=0;
int f[200010];
int sum[200010];
struct edge
{
	int u,v;
}e[200010];
int find(int x){return f[x]==x?x:f[x] = find(f[x]);}

void unix(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
	{
		f[fx]=fy;
	}
	else
	{
		c++;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	while(cin>>n>>m)
	{
		c=0;
		memset(sum,0,sizeof(sum));
		for( i = 1 ; i <= n ; i++)
			f[i]=i;
		for( i = 0 ; i < m ; i++)
		{
			int u,v;
			cin>>u>>v;
			e[i].u=u,e[i].v=v;
			sum[u]++;
			sum[v]++;
		}
		for( i = 0 ; i < m ; i++)
		{
			if(sum[e[i].u]==2&&sum[e[i].v]==2)
			{
				unix(e[i].u,e[i].v);
			}
		}
		cout<<c<<endl;
	}
	return 0;
}