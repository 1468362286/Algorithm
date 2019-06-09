#include <stdio.h>

int main(){
	int a,b,n,x,y,flag;
	while (~scanf("%d%d%d",&n,&a,&b))
	{
		flag = 0;
		for (int i=0;i<(n/a+1);i++)
		{
			if((n-i*a)%b==0)
			{
				flag =1;
				x=i;
				y=(n-i*a)/b;
				break;
			}
		}
		if (flag)
		printf ("%s\n%d %d\n","YES",x,y);
		else printf ("%s\n","NO");
	}
	return 0;
	}