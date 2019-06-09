#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 200010;
typedef _int64 ll;
map<int,ll> s1,s2;


int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i;
	ll x;
	while(~scanf("%d%d",&n,&k))
	{
		s1.clear(),s2.clear();
		ll ans=0;
		for( i = 0 ; i < n; i++)
		{
			scanf("%I64d",&x);
			if(x%k==0)
			{
				ll t1 = s2[x/k];
				ans+=t1;
				ll t2 = s1[x/k];
				s2[x]+=t2;
			}
			s1[x]++;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}