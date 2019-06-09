#include <stdio.h>

int a[100];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,x;
	while(~scanf("%d",&n))
	{
		int pre=0;
		int flag=0;
		int ans = 0;
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d",&x);
			a[i]=x;
			if(!flag)
			{
				if(pre+15<x)
				{
					ans = pre+15;
					flag=1;
				}
				else
				{
					pre=x;
				}
			}
		}
		printf("%d\n",pre+15>90?90:pre+15);
	}
	return 0;
}