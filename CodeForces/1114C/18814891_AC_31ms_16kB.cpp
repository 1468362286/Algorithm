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
ll min(ll a,ll b){return a>b?b:a;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	ll n,b;
	while(~scanf("%I64d%I64d",&n,&b))
	{
		ll ans=1000000000000000000;
		for( ll i = 2 ; i <= b ; i++)
		{
			if(1*i*i>b)i=b;
			int cnt=0;
			while(b%i==0){b/=i;cnt++;}
			if(cnt==0)continue;
			ll tmp=0,mul=1;
			while(mul<=n/i){mul*=i;tmp+=n/mul;}
			ans=min(ans,tmp/cnt);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}