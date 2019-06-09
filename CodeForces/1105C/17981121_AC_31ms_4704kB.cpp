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
const int maxn = 200010;
const ll mod = 1000000007;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
ll dp[maxn][3];
int main()
{
#ifdef _DEBUG
    freopen("in.txt","r",stdin);
#endif
	ll n,l,r,i;
	ll cnt0,cnt1,cnt2;
	while(~scanf("%I64d%I64d%I64d",&n,&l,&r))
	{
		cnt0=r/3-(l-1)/3;
		cnt1=(r+2)/3-(l+1)/3;
		cnt2=(r+1)/3-l/3;
		dp[1][0]=cnt0,dp[1][1]=cnt1,dp[1][2]=cnt2;
		for( i = 2 ; i <= n ; i++)
		{
			dp[i][0]=(dp[i-1][0]*cnt0)%mod+(dp[i-1][1]*cnt2)%mod+(dp[i-1][2]*cnt1)%mod;
			dp[i][1]=(dp[i-1][0]*cnt1)%mod+(dp[i-1][1]*cnt0)%mod+(dp[i-1][2]*cnt2)%mod;
			dp[i][2]=(dp[i-1][0]*cnt2)%mod+(dp[i-1][1]*cnt1)%mod+(dp[i-1][2]*cnt0)%mod;
		}
		printf("%I64d\n",dp[n][0]%mod);
	}
    return 0;
}