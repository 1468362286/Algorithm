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
const int maxn = 150010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int f[maxn],nex[maxn],pre[maxn],ind[maxn];
vector<int>e[maxn];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}

void dfs(int nx,int px)
{
	cout<<nx<<" ";
	for(int i = 0 ; i < e[nx].size() ; i++)
	{
		int to = e[nx][i];
		if(to!=px)dfs(to,nx);
	}
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int i,n,x,y;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			pre[i]=f[i]=i,nex[i]=i,ind[i]=0;
		for( i = 1 ; i < n ; i++)
		{
			cin>>x>>y;
			int fx=find(x),fy=find(y);
			int r=nex[fx],l=pre[fy];
			e[r].push_back(l);e[l].push_back(r);
			ind[l]++;ind[r]++;
			nex[fx]=nex[fy];pre[fy]=pre[fx];
			f[fy]=fx;
		}
		for( i = 1 ; i <= n ; i++)
		{
			if(ind[i]==1)
			{
				dfs(i,-1);break;
			}
		}
	}
	return 0;
}		