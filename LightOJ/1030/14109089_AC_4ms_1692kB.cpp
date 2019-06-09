#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
double dp[110];
double a[110];
int min(int a,int b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int T,i,j,n;
	cin>>T;
	int cases=0;
	while(T--)
	{
		cases++;
		cin>>n;
		for( i = 0 ; i < n ; i++)
		{
			cin>>a[i];
			dp[i]=a[i];
		}
		for( i = n-2 ; i >= 0 ; i--)
		{
			int x = min(6,n-1-i);
			for( j = 1 ; j <= x ; j++)
			{
				dp[i]+=dp[i+j]*(1.0/x);
			}
		}
		printf("Case %d: %lf\n",cases,dp[0]);
	}
	return 0;
}