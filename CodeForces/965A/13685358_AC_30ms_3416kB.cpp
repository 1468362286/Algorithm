#include <iostream>
#include <string>
#include <math.h>
using namespace std;
typedef _int64 ll;
int main()
{
	//freopen("in.txt","r",stdin);
	int k,n,s,p;
	while(~scanf("%d%d%d%d",&k,&n,&s,&p))
	{
		printf("%d\n",((k*((n+s-1)/s))+p-1)/p);
	}
	return 0;
}