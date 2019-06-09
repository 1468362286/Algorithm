#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set> 
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;
const int maxn = 100010;
const int inf = 0x3ffffff;
typedef _int64 ll;
const ll INF=8e18;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
ll a[maxn];
ll s[maxn];
vector<int>vec[maxn];

void dfs(int x,int pre)
{
	int i;
	if(s[x]==-1)
	{
		ll mina=INF;
		for( i = 0 ; i < vec[x].size() ; i++)
		{
			int to = vec[x][i];
			mina=min(mina,s[to]);
		}
		if(vec[x].size()==0)
			s[x]=s[pre];
		else
			s[x]=mina;
	}
	a[x]=s[x]-s[pre];
	for( i = 0 ; i < vec[x].size() ; i++)
	{
		int to = vec[x][i];
		dfs(to,x);
	}
}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i;
	ll x;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			vec[i].clear();
		for( i = 2 ; i <= n ; i++)
		{
			scanf("%I64d",&x);
			vec[x].push_back(i);
		}
		for( i = 1 ; i <= n ; i++)
			scanf("%I64d",&s[i]);
		dfs(1,-1);
		ll ans=0;
		for( i = 1 ; i <= n ; i++)
		{
			if(a[i]<0)
			{
				ans=-1;
				break;
			}
			ans+=a[i];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}