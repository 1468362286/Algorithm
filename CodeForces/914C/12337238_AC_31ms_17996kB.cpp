#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
const int N = 1010;
typedef _int64 ll;
ll k,a[N],dp[N][N],l,mod=1e9+7,ans1[N],cnt,C[N][N];
void init()
{
	C[1][0]=C[1][1]=1;
	for(int i = 2 ; i < 1010 ; i++)
	{
		C[i][0]=1;
		for(int j = 1 ; j < 1010 ; j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
}

ll get(ll x)
{
	ll sum=0;
	while(x)
	{
		if(x&1)++sum;
		x>>=1;
	}
	return sum;
}
ll c(ll a,ll b)
{
	if(a<b)return 0;
	else
		return C[a][b];
}
int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	int k;
	ll i,j;
	init();
	while(cin>>s)
	{
		cin>>k;
		l = s.size();
		for(ll i = l-1 ; i>=0 ; i--)
			a[l-i]=s[i]-'0';
		if(a[1])
			dp[1][1]=1,dp[1][0]=1;
		else
			dp[1][1]=0,dp[1][0]=1;
		for( i = 2 ; i <= l ;i++)
		{
			dp[i][0]=1;
			for( j = 1 ; j <= l ; j++)
			{
				if(a[i])
					dp[i][j]=(dp[i-1][j-1]+c(i-1,j))%mod;
				else
					dp[i][j]=dp[i-1][j]%mod;
			}
		}
		ll ans=0;
		for( i = 1 ; i <= 1000 ; i++)
		{
			ll tmp = get(i);
			if(i==1)
				ans1[i]=0;
			else
				ans1[i]=ans1[tmp]+1;
			if(ans1[i]==k-1)
				ans=(ans+dp[l][i])%mod;
		}
		if(k==0)
			ans=1;
		if(k==1)
			ans=dp[l][1]-1;
		printf("%I64d\n",ans);
	}
	return 0;
}