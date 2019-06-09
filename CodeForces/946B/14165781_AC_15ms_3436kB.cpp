#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;

int main()
{
//	freopen("in.txt","r",stdin);
	ll a,b;
	while(~scanf("%I64d%I64d",&a,&b))
	{
		
		while(1)
		{
			if(a==0||b==0)
				break;
			if(a>=2*b)
			{
				//a-=2*b;
				a%=2*b;
				continue;
			}
			if(b>=2*a)
			{
				//b-=2*a;
				b%=2*a;
				continue;
			}
			else
				break;
		}
		
		printf("%I64d %I64d\n",a,b);
	}
	return 0;
}

