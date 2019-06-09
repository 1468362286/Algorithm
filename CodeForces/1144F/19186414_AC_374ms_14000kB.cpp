#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn=200010;
const int inf = 0x7fffffff;
typedef _int64 ll;
vector<int>vec[maxn];
int color[maxn];
struct Edge
{
	int u,v;
}edge[maxn];
int flag;
int min(int a,int b){return a>b?b:a;}

void dfs(int x,int v)
{
	color[x]=v;
	for(int i = 0 ; i < vec[x].size() ; i++)
	{
		int to = vec[x][i];
		if(color[to]==-1)
		{
			dfs(to,v^1);
		}
		else 
		{
			if(color[x]==color[to])
				flag=1;
		}
	}
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,m,u,v,i;
	while(cin>>n>>m)
	{
		flag=0;
		for( i = 1 ; i <= n ; i++)
			vec[i].clear();
		for( i = 0 ; i < m ; i++)
		{
			cin>>u>>v;
			edge[i].u=u,edge[i].v=v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		memset(color,-1,sizeof(color));
		dfs(1,0);
		if(flag)
		{
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for( i = 0 ; i < m ; i++)
		{
			if(color[edge[i].u]>color[edge[i].v])
			{
				cout<<"1";
			}
			else
				cout<<"0";
		}
		cout<<endl;
	}
	return 0;
}	