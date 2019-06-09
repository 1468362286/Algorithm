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
const int maxn = 300010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
const ll mod = 998244353;
vector<int>vec[maxn];
ll cnt1,cnt2;
int color[maxn];
int flag;

ll quick_pow(ll a,ll b,ll c)
{
	ll sum=1;
	while(b)
	{
		if(b&1)sum=sum*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return sum;
}
void dfs(int x,int pre)
{
	int i;
	if(flag)return;
	if(color[x]==-1)
	{
		if(pre==-1)
			color[x]=1,cnt1++;
		else
			if(color[pre]==1)
				color[x]=2,cnt2++;
			else
				color[x]=1,cnt1++;
	}
	else
	{
		flag=1;
		return;
	}
	for( i = 0 ; i < vec[x].size() ; i++)
	{
		int to = vec[x][i];
		if(to!=pre)
		{
			dfs(to,x);
		}
	}
}

void dfs1(int x,int c){
    if(c==1) cnt1++;
    if(c==2) cnt2++; 
    color[x]=c;
	for(int i = 0 ; i < vec[x].size() ; i++)
	{
		int to = vec[x][i];
		if(color[to]==-1)
		{
			dfs1(to,3-c);
		}
		else if(color[to]==c)
		{
			flag=1;
			return;
		}
	}
} 

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int t,n,m,u,v,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		flag=0;
		for( i = 1 ; i <= n ; i++)
			vec[i].clear();
		for( i = 0 ; i < m ; i++)
		{
			scanf("%d%d",&u,&v);
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
	//	memset(color,-1,sizeof(color));
		for( i = 1 ; i <= n ; i++)
			color[i]=-1;
		ll ans=1;
		for( i = 1 ; i <= n ; i++)
		{
			if(color[i]==-1)
			{
				cnt1=0,cnt2=0;
				dfs1(i,1);
				ans*=(quick_pow(2,cnt1,mod))%mod+(quick_pow(2,cnt2,mod));
				ans%=mod;
				if(flag)break;
			}
		}
		if(flag)
		{
			cout<<0<<endl;
			continue;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
