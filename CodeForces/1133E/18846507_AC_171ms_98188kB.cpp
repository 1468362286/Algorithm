#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn=200010;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,k,i,j;
	cin>>n>>k;
	vector<int>a(n);
	for( i = 0 ; i < n ; i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	vector<int>cnt(n);
	for( i = 0 ; i < n ; i++)
	{
		while(i+cnt[i]<n&&a[i+cnt[i]]-a[i]<=5)
		{
			++cnt[i];
		}
	}
	vector<vector<int> >dp(n+1,vector<int>(k+1));
	for( i = 0 ; i < n ; i++)
		for( j = 0 ; j <= k ; j++)
		{
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			if(j+1<=k)
			{
				dp[i+cnt[i]][j+1]=max(dp[i+cnt[i]][j+1],dp[i][j]+cnt[i]);
			}
		}
	cout<<dp[n][k]<<endl;
	return 0;
}