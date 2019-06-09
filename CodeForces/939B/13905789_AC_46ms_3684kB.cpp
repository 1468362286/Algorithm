#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
int main()
{
	//freopen("in.txt","r",stdin);
	int k,i;
	ll n,x;
	while(~scanf("%I64d%d",&n,&k))
	{
		ll maxi = -1;
		ll ansi,ansj;
		for( i = 0 ; i < k ; i++)
		{
			scanf("%I64d",&x);
			ll tmp = n/x*x;
			if(tmp>maxi)
			{
				maxi=tmp;
				ansi = i+1;
				ansj = n/x;
			}
		}
	//	cout<<ansi<<" "<<ansj<<endl;
		printf("%I64d %I64d\n",ansi,ansj);
	}
	return 0;
}