#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;

int fun(ll x)
{
	int ans=0;
	while(x)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	ll n;
	while(~scanf("%I64d",&n))
	{
		ll tmp= n/2;
		int cnt=0;
		ll ans=0;
		while(tmp)
		{
			if(tmp<10)
				ans=tmp;
			tmp/=10;
			cnt++;
		}
		for(int i = 1 ; i < cnt ; i++)
		{
			ans=ans*10+9;
		}
		printf("%d\n",fun(ans)+fun(n-ans));
	}
	return 0;
}