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
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
const int mod = 1e9+7;
int res[17] = {0,1,0,18,0,1800,0,670320,0,734832000,0,890786230,0,695720788,0,150347555,0};
ll ans;
int n;
ll jie[17];

void dfs(int a,int b,int c)
{
	if(a==n+1)
	{
		ans++;
		if(ans>=mod)
			ans-=mod;
		return;
	}
	int v;
	for(int i = 0 ; i < n ; i++)
	{
		if(((1<<i)&b)==0)
		{
			v=(i+a-1)%n;
			if(((1<<v)&c)==0)
				dfs(a+1,b|(1<<i),c|(1<<v));
		}
	}
}

void init()
{
	jie[0]=1;
	for(int i = 1 ; i < 17 ; i++)
		jie[i]=i*jie[i-1]%mod;
	ans=0;
	n=15;
	dfs(1,0,0);
	printf("%I64d\n",ans*jie[n]);
}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	//init();
	while(cin>>n)
	{
		cout<<res[n]<<endl;
	}
	return 0;
}