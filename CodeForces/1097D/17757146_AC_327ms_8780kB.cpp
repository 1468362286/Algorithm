#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const int maxn = 10100;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
ll n,m,ans=1,dp[maxn][110],ny[maxn];
const ll Mod = 1000000007;
const ll MN = 40000000;
inline ll po(ll u,ll v)
{
	ll res=1;
	for(;v;)
	{
		if(v&1)res=res*u%Mod;
		u=u*u%Mod;
		v>>=1;
	}
	return res;
}

inline void calc(ll u,ll v)
{
	ll i,j,k,t,res=0;
	for( i = 0 ; i <= m ; i++)
		for( j = 0 ; j <= u ; j++)
			dp[i][j]=0;
	dp[0][u]=1;
	for( i = 0 ; i < m ; i++)
	{
		for( j = u ; j >= 0 ; j--)
		{
			for( k = 0 ; k <= j ; k++)
			{
				dp[i+1][k]+=dp[i][j]*ny[j+1]%Mod;
				if(dp[i+1][k]>Mod)dp[i+1][k]-=Mod;
			}
		}
	}
	t=1;
	for( i = 0 ; i <= u ; i++)
	{
		res+=dp[m][i]*t%Mod;
		if(res>Mod)res%=Mod;
		t=t*v%Mod;
	}
	ans*=res;
	ans%=Mod;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	ll i,t;
	scanf("%I64d%I64d",&n,&m);
	for( i = 1 ; i <= 100 ; i++)
		ny[i]=po(i,Mod-2);
	for( i = 2 ; n!=1&&i<=MN ; i++)
	{
		if(n%i)continue;
		t=0;
		for(;n%i==0;t++)n/=i;
		calc(t,i);
	}
	if(n)calc(1,n);
	printf("%I64d\n",ans);
	return 0;
}