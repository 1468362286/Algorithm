#include <stdio.h>
#include <math.h>
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,x,y;
	while(~scanf("%d",&n))
	{
		int a = 0,b=0;
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d%d",&x,&y);
			if(x>0)a++;
			else if(x<0)b++;
		}
		if(a==1||b==1||a==n||b==n)
		{
			printf("Yes\n");
		}
		else
			printf("No\n");
	}
	return 0;
}