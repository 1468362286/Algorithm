#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
#include <utility>
#include <time.h>
#include <numeric>
using namespace std;
const int maxn = 510;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
typedef _int64 ll;
#define x first
#define y second 
vector<int> p,rk;

int getp(int v)
{
	if(v==p[v])return v;
	return p[v]=getp(p[v]);
}

bool merge(int v,int u)
{
	u = getp(u);
	v = getp(v);
	if(u==v)return false;
	if(rk[u]<rk[v])swap(u,v);
	rk[u]+=rk[v];
	p[v]=u;
	return true;
}
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
{
	return a.y<b.y;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,m,i,j,k;
	cin>>n>>m;
	p=vector<int>(n);
	for( i = 0 ; i < n ; i++)
		p[i]=i;
	rk=vector<int>(n,1);
	vector<pair<pair<int,int>,int> > e(m);
	for( i = 0 ; i < m ; i++)
	{
		cin>>e[i].x.x>>e[i].x.y>>e[i].y;
		--e[i].x.x;
		--e[i].x.y; 
	}
	sort(e.begin(),e.end(),cmp);
	int ans=0;
	for( i = 0 ; i < m ; i++)
	{
		j = i;
		while(j<m&&e[i].y==e[j].y)
		{
			++j;
		}
		int cnt=j-i;
		for( k = i ; k < j ; ++k)
			if(getp(e[k].x.x)==getp(e[k].x.y))
			{
				--cnt;
			}
		for( k = i ; k < j ; ++k)
			cnt-=merge(e[k].x.x,e[k].x.y);
		ans+=cnt;
		i=j-1;
	}
	cout<<ans<<endl;
	return 0;
}