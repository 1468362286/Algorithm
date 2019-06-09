#include <stdio.h>
#include <iostream>
#include <utility>
#include <math.h>
using namespace std;

const int maxn = 100010;
struct Node
{
	double r,x,y;
}node[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	double R,d;
	while(~scanf("%lf%lf",&R,&d))
	{
		int ans = 0;
		scanf("%d",&n);
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%lf%lf%lf",&node[i].x,&node[i].y,&node[i].r);
		//	printf("%lf%lf%lf\n",node[i].x,node[i].y,node[i].r);
			double tmp = sqrt(node[i].x*node[i].x+node[i].y*node[i].y);
			if((tmp-node[i].r>=R-d)&&(tmp+node[i].r<=R))
			{
		//		printf("%d\n",i);
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}