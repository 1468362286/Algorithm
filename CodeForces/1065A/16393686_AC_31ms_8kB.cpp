#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
int main()
{
	int t;
	ll s,a,b,c;
	cin>>t;
	while(t--)
	{
		scanf("%I64d%I64d%I64d%I64d",&s,&a,&b,&c);
		ll tmp = s/c;
		tmp+=(tmp/a)*b;
		printf("%I64d\n",tmp);
	}
	return 0;
}