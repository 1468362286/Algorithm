#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 5010;
int n,m,s;
vector<int> vec[maxn];
int vist[maxn],vis[maxn];
int needLink[maxn];

void dfs(int x)
{
//	vis[x]=1;
	vist[x]=1;
	for(int i = 0 ; i < vec[x].size() ; i++)
	{
		int to = vec[x][i];
		if(!vist[to])
		{
		//	vist[to]=1;
			dfs(to);
		//	vist[to]=0;
		}
	}
}

void dfs1(int x)
{
	vist[x]=1;
	for(int i = 0 ; i < vec[x].size() ; i++)
	{
		int to = vec[x][i];
		/*
		if(ff[x][to]==2)
			continue;
		if(ff[x][to]==1)
		{
			cn++;
			ff[x][to]=2;
			continue;
		}*/
		if(!vist[to])
		{
		//	vist[to]=1;
			needLink[to]=0;
			dfs1(to);
	//		vist[to]=0;
		}
	}
}
int solve()
{
	memset(vist,0,sizeof(vist));
	memset(vis,0,sizeof(vis));
	memset(needLink,0,sizeof(needLink));
//	vist[s]=1;
	dfs(s);
	int cnt=0,i;
	for( i = 1 ; i <= n ; i++)
		if(!vist[i])
			needLink[i]=1;	//ggl
	for( i = 1 ; i <= n ; i++)
	{
		if(needLink[i])
		{
		//	needLink[i]=1;
		//	cnt++;
		//	vec[s].push_back(i);
		//	ff[s][i]=1;
			memset(vist,0,sizeof(vist));
		//	vist[i]=1;
			dfs1(i);
		}
	}
	for( i = 1 ; i <= n ; i++)
	{
		if(needLink[i])
			cnt++;
	}
	return cnt;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int i,u,v;
	while(cin>>n>>m>>s)
	{
		for( i = 1 ; i <= n ; i++)
			vec[i].clear();
		for( i = 0 ; i < m ; i++)
		{
			cin>>u>>v;
			vec[u].push_back(v);
		}
		cout<<solve()<<endl;
	}
	return 0;
}