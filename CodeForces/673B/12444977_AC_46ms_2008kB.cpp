#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,x,y;
	while(~scanf("%d%d",&n,&m))
	{
		int r=1,l=n;
		for(int i = 0 ; i < m ; i++)
		{
			scanf("%d%d",&x,&y);
			if(x>y)swap(x,y);
			if(r<x)
				r=x;
			if(l>y)
				l=y;
		}
		if(l-r<0)
			printf("0\n");
		else
		printf("%d\n",l-r);
	}
	return 0;
}