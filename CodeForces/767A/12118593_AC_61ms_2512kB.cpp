#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
const int maxn = 100010;
bool vist[maxn];
int a[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j;
	while(~scanf("%d",&n))
	{
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",&a[i]);
			vist[i] = 0;
		}
		int next = n;
		for( i = 1 ; i <= n ; i++)
		{
			vist[a[i]] = true;
			if(vist[next])
			{
				for( j = next ; j >= 1 ; j--)
				{
					if(vist[j])
					{
						printf("%d ",j);
					}
					else
					{
						next = j;
						break;
					}
				}
				printf("\n");

			}
			else
				printf("\n");
		}
	}
	return 0;
}