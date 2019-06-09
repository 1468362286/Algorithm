#include <iostream>
#include <string>
using namespace std;
#define N 1010
#define Mod 998244353
typedef _int64 ll;
int n,k;
ll dp[N][N],ans=0;
ll sum[N][N];
int min(int a,int b){return a>b?b:a;}
int main()
{
	int i,j,p;
	cin>>n>>k;
	dp[0][0]=1;
	for( i = 1 ; i <= n ; i++)
		for( j = 1 ; j <= i ; j++)
			for( p = 1 ; p <= j ; p++)
				dp[i][j]=(dp[i][j]+dp[i-p][min(j,i-p)])%Mod;
	for( i = n ; i >= 1 ; i--)
		dp[n][i]=(dp[n][i]-dp[n][i-1]+Mod)%Mod;
	for( i = 1 ; i <= n ; i++)
		for( j = 1 ; j*i<k ; j++)
			ans=(ans+dp[n][i]*dp[n][j]%Mod)%Mod;
	ans=(ans*2)%Mod;
	printf("%I64d\n",ans);
	return 0;
} 

