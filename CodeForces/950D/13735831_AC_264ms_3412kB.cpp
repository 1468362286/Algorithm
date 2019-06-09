#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;

int main()
{
	//freopen("in.txt","r",stdin);
	ll n,q,x;
	while(~scanf("%I64d%I64d",&n,&q))
	{
		while(q--)
		{
			scanf("%I64d",&x);
			while(x%2==0)
				x=x/2+n;
			printf("%I64d\n",(x-1)/2+1);
		}
	}
	return 0;
}