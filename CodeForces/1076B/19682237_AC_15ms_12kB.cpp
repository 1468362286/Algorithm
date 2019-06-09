#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 100010;
typedef _int64 ll;


ll find(ll x)
{
	ll tmp=ll(sqrt(double(x)));
	for(ll i = 3 ; i <= tmp ; i+=2)
	{
		if(x%i==0)return i;
	}
	return x;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	ll n;
	while(~scanf("%I64d",&n))
	{
		ll cnt=0;
		if(n%2==0)
		{
			cnt=n/2;
		}
		else
		{
			n-=find(n);
			cnt=n/2+1;
		}
		printf("%I64d\n",cnt);
	}
	return 0;
}