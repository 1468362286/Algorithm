#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
int main()
{
	ll l,r;
	while(~scanf("%I64d%I64d",&l,&r))
	{
		cout<<"YES"<<endl;
		for(ll i = l ; i <= r ; i+=2)
			printf("%I64d %I64d\n",i,i+1);
	}
	return 0;
}