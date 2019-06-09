#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;

int main()
{
	//freopen("in.txt","r",stdin);
	ll n,k;
	while(~scanf("%I64d%I64d",&n,&k))
	{
		ll ans=0;
		if(n+n-1<k)
		{
			cout<<"0"<<endl;
			continue;
		}
		if(k>1+n)
		{
			ans = n-(k-n)+1;
		}
		else
		{
			ans = k-1;
		}
		printf("%I64d\n",ans/2);
	}
	return 0;
}