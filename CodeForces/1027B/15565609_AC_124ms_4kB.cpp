#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
int main()
{
	//freopen("in.txt","r",stdin);
	ll n,q,x,y,ans;
	while(~scanf("%I64d%I64d",&n,&q))
	{
		while(q--)
		{
			scanf("%I64d%I64d",&x,&y);
			ans = (x-1)*n+y+1;
			if((x+y)%2!=0)
			{
				ans+=n*n;
			}
			printf("%I64d\n",ans/2);
		}
	}
	return 0;
}