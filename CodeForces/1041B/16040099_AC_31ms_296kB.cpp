#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll min(ll a,ll b){return a>b?b:a;}
int main()
{
	ll x,y,a,b;
	while(~scanf("%I64d%I64d%I64d%I64d",&x,&y,&a,&b))
	{
		ll tmp=gcd(a,b);
		a = a/tmp;
		b = b/tmp;
		printf("%I64d\n",min(x/a,y/b));
	}
	return 0;
}