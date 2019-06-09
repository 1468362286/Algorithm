#include <stdio.h>
#include <vector>
using namespace std;
const int maxn = 10010;
int e[maxn];
//int vist[maxn];
int color[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,x;
	while(~scanf("%d",&n))
	{
		for( i = 2 ; i <= n ; i++)
		{
			scanf("%d",&x);
			e[i] = x;
		}
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",&x);
			color[i]=x;
		}
		int cnt = 1;
		for( i = 2 ; i <= n ; i++)
		{
			if(color[i]!=color[e[i]])
			{
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}