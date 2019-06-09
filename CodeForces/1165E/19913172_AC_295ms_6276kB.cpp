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
const int maxn = 200010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
const ll mod = 998244353;
int b[maxn];
int a[maxn];
ll c[maxn];
ll val[maxn];
ll pre_sum[maxn];
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		for( i = 1 ; i <= n ; i++)
			cin>>b[i];
		for( i = 1 ; i <= n ; i++)
		{
			val[i]=ll(a[i])*ll(i)*ll(n-i+1);
		}
		sort(val+1,val+n+1);
		sort(b+1,b+n+1,cmp);
		ll sum=0;
		for( i = 1 ; i <= n ; i++)
			c[i]=(val[i]%mod*ll(b[i]))%mod,sum=(sum+c[i]%mod);
		sum%=mod;
		printf("%I64d\n",sum);
	}
	return 0;
}