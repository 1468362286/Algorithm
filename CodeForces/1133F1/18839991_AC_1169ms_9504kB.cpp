#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn=200010;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
vector<int>vec[maxn];
int degree[maxn];
int vist[maxn];
void bfs(int x)
{
	queue<int>p;
	while(!p.empty())p.pop();
	p.push(x);
	while(!p.empty())
	{
		int u=p.front();
		p.pop();
		for(int i = 0 ; i < vec[u].size() ; i++)
		{
			int to = vec[u][i];
			if(!vist[to])
			{
				cout<<u<<" "<<to<<endl;
				vist[to]=1;
				p.push(to);
			}

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
		for( i = 0 ; i < m ; i++)
		{
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
			degree[u]++,degree[v]++;
		}
		int maxi = 0,maxii=0;
		for( i = 1 ; i <= n ; i++)
		{
			if(degree[i]>maxi)
			{
				maxi = degree[i];
				maxii = i;
			}
		}
		memset(vist,0,sizeof(vist));
		vist[maxii]=1;
		bfs(maxii);
	}
	return 0;
}