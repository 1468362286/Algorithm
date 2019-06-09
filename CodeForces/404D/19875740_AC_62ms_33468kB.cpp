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
const int maxn = 1000010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
ll dp[maxn][4];
const ll mod = 1e9+7;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	string s;
	int i;
	while(cin>>s)
	{
		string tmp=" ";
		tmp+=s;
		s=tmp;
		ll ans=0;
		dp[0][0]=dp[0][1]=1;
		for( i = 1 ; i < s.size() ; i++)
		{
			if(i==s.size()-1)
			{
				if(s[i]=='0')
				{
					ans=dp[i-1][0];
				}
				else if(s[i]=='1')
				{
					ans=dp[i-1][2];
				}
				else if(s[i]=='2')
				{
					ans=0;
				}
				else if(s[i]=='*')
				{
					ans=(dp[i-1][1]+dp[i-1][3])%mod;
				}
				else if(s[i]=='?')
				{
					ans=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%mod;
				}
				continue;
			}
			if(s[i]=='0')
				dp[i][0]=dp[i-1][0]%mod;
			else if(s[i]=='1')
			{
				dp[i][0]=dp[i-1][2]%mod;
				dp[i][1]=dp[i-1][0]%mod;
			}
			else if(s[i]=='2')
			{
				dp[i][1]=dp[i-1][2]%mod;
			}
			else if(s[i]=='*')
			{
				dp[i][2]=(dp[i-1][1]+dp[i-1][3])%mod;
				dp[i][3]=(dp[i-1][1]+dp[i-1][3])%mod;
			}
			else if(s[i]=='?')
			{
				dp[i][0]=(dp[i-1][0]+dp[i-1][2])%mod;
				dp[i][1]=(dp[i-1][0]+dp[i-1][2])%mod;
				dp[i][2]=(dp[i-1][1]+dp[i-1][3])%mod;
				dp[i][3]=(dp[i-1][1]+dp[i-1][3])%mod;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}