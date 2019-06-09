#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
int q;
ll n,m,k;

int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%I64d%I64d%I64d",&n,&m,&k);
		if(n>m)swap(n,m);
		if(m>k){puts("-1");continue;}
		if((m-n)&1)k--;
		else if((k-m)&1)k-=2;
		printf("%I64d\n",k);
	}
	return 0;
}