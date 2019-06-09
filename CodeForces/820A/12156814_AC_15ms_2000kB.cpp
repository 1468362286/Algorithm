#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int c,v0,v1,a,l,i;
	while(~scanf("%d%d%d%d%d",&c,&v0,&v1,&a,&l))
	{
		int tmp = 0;
		for( i = 1 ; ; i++)
		{
			tmp = v0+(i-1)*a;
			if(tmp>v1)
				tmp = v1;
			if(i>1)
				c+=l;
			c=c-tmp;
			if(c<=0)
				break;
		}
		printf("%d\n",i);
	}
	return 0;
}