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
const int maxn = 100010;
const int inf = 0x3ffffff;
typedef _int64 ll;
ll min(ll a,ll b){return a>b?b:a;}
ll max(ll a,ll b){return a>b?a:b;}

int solve(ll x)
{
	int cnt=0;
	while(x)
	{
		x>>=1;
		cnt++;
	}
	return cnt;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	ll s,t,i,j;
	while(~scanf("%I64d%I64d",&s,&t))
	{
		int S = solve(s);
		int T = solve(t);
		int ans=0;
		for( i = S ; i <= T ; i++)
		{
			ll tmp = (ll(1)<<i)-1;
			for( j = 0 ; j < i-1 ; j++)
			{
				ll p = tmp-(ll(1)<<j);
				if(p>=s&&p<=t)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}