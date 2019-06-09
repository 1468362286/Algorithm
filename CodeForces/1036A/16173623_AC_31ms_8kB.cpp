#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;

int main()
{
	ll n,k;
	while(~scanf("%I64d%I64d",&n,&k))
	{
		if(k<=n)
			printf("1\n");
		else
			printf("%I64d\n",k%n==0?k/n:k/n+1);
	}
	return 0;
}