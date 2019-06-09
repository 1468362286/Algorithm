#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
const int inf = 0x7fffffff;
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,x;
	while(~scanf("%d",&n))
	{
		int ans = -inf;
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d",&x);
			if(int(sqrt(x))!=sqrt(x)||x<0)
			{
				ans=max(x,ans);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}