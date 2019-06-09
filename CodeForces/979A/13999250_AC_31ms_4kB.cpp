#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
int main()
{
	//freopen("in.txt","r",stdin);
	ll n;
	while(~scanf("%I64d",&n))
	{
		
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		if((n+1)%2==0)
			printf("%I64d\n",(n+1)/2);
		else
			printf("%I64d\n",n+1);
	}	
	return 0;
}