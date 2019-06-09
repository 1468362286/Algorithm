#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef _int64 ll;
#define sc(d) scanf("%d",&d)
int min(int a,int b){return a>b?b:a;}
int n;
int c[200005];
int g[200005];

struct DisjointSet
{
	vector<int>father,rank;

	DisjointSet(int n):father(n+1),rank(n+1)
	{
		for(int i = 1 ; i <= n ; i++)
			father[i]=i;
	}
	int find(int v){return father[v]=father[v]==v?v:find(father[v]);}

	void merge(int x,int y)
	{
		int a=find(x),b=find(y);
		if(rank[a]<rank[b])
			father[a]=b;
		else
		{
			father[b]=a;
			if(rank[b]==rank[a])
				++rank[a];
		}
	}
};
int v[200005];
int vist[200005];

ll ans=0;

int dfs(int ind,int minc=200000)
{
	v[ind]++;
	if(v[ind]>=3)
	{
		ans+=minc;
		return 1;
	}
	if(v[ind]==2)
		dfs(g[ind],min(minc,c[ind]));
	else
		dfs(g[ind],minc);
	return 0;
}
int main()
{
	int i;
	sc(n);
	for( i = 1 ; i <= n ; i++)
		sc(c[i]);
	for( i = 1 ; i <= n ; i++)
		sc(g[i]);
	DisjointSet d(n);
	for( i = 1 ; i <= n ; i++)
		d.merge(i,g[i]);
	for( i = 1 ; i <= n ; i++)
		if(vist[d.find(i)]==0)
		{
			vist[d.find(i)]=1;
			dfs(d.find(i));
		}
	printf("%I64d\n",ans);
	return 0;
}