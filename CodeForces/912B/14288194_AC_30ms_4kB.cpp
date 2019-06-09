#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
ll max(ll a,ll b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	ll n,k;
	while(~scanf("%I64d%64d",&n,&k))
	{
		if(k==1)
		{
			printf("%I64d\n",n);
			continue;
		}
		int cnt=0;
		while(n)
		{
			cnt++;
			n>>=1;
		}
		ll S = (ll(1)<<(cnt))-1;
	//	if(n==S)
			printf("%I64d\n",S);
	//	else
		//	printf("%I64d\n",max(n,S-n));
	}
	return 0;
}