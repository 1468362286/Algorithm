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
ll min(ll a,ll b){return a>b?b:a;}
ll max(ll a,ll b){return a>b?a:b;}
int dp[510][510];

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i,j,k;
	while(cin>>n)
	{
		for( j = 2 ; j <= n-1 ; j++)
			for( i = 1 ; i+j <= n ; i++)
			{
				dp[i][i+j]=inf;
				for( k = i+1 ; k < i+j ; k++)
				{
					dp[i][i+j]=min(dp[i][i+j],dp[i][k]+dp[k][i+j]+i*(i+j)*k);
				}
			}
		cout<<dp[1][n]<<endl;
	}
	return 0;
}