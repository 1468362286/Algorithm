#include <iostream>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
int a[2003],dp[2003][2003];
int main()
{
	int N,i,j;
	while(cin>>N)
	{
		int max = -999999;
		for( i = 1 ; i <= N ; i++)
		{
			cin>>a[i];
		}

		for( i = N ; i >0 ; i--)
		{
			for( j = i ; j<=N ; j++)
			{
				dp[i][j] = max(dp[i+1][j]+a[i]*(N+i-j),dp[i][j-1]+a[j]*(N+i-j));
			}
		}
		cout<<dp[1][N]<<endl;
	}
	return 0;
}