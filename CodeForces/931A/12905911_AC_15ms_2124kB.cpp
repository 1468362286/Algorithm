#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int a,b,tmp;
	while(~scanf("%d%d",&a,&b))
	{
		int ans=0;
		if(a>b)swap(a,b);
		tmp=b-a;
		int p=1;
		for(int i = 1 ; i <= tmp ; i++)
		{
			ans+=p;
			if(i%2==0)
				p++;
		}
		printf("%d\n",ans);
	}
	return 0;
}