#include <stdio.h>
#include <vector>
using namespace std;
vector<int> p[100010];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,k,x,i,j;
	while(~scanf("%d%d%d",&n,&k,&m))
	{
		int flag = 0;
		for( i = 0 ; i < m ; i++)
		{
			p[i].clear();
		}
		int tmp;
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",&x);
			p[x%m].push_back(x);
		}
		
		for( i = 0 ; i < m ; i++)
		{
			if(p[i].size()>=k)
			{
				printf("Yes\n");
				flag=1;
				for( j = 0 ; j < k-1 ; j++)
				{
					printf("%d ",p[i][j]);
				}
				printf("%d\n",p[i][j]);
				break;
			}
		}
		
		if(!flag)
			printf("No\n");
	}
	return 0;
}
