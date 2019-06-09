#include <iostream>
using namespace std;
#define max(a,b) (a>b?a:b)
int main()
{
//	freopen("in.txt","r",stdin);
	int T;
	int maxn = 0;
	while(~scanf("%d",&T))
	{
		while(T)
		{
			maxn=max(maxn,T%10);
			T/=10;
		}
		printf("%d\n",maxn);
	}
	return 0;
}