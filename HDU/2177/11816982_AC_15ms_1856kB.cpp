#include <stdio.h>
#include <math.h>

int main()
{
	//freopen("in.txt","r",stdin);
	double x = (1+sqrt(5.0))/2.0;
	int i,k,temp,n,m,a,b;
	while(~scanf("%d%d",&a,&b)&&(a+b))
	{
		if(a>b)
		{
			temp = a;
			a = b;
			b = temp;
		}
		k = b-a;
		if((int)(k*x)==a)
			printf("%d\n",0);
		else
		{
			printf("%d\n",1);
			for( i = 1 ; i <= a ; i++)
			{
				n = a-i;
				m = b-i;
				k = m-n;
				if((int)(k*x)==n)
					printf("%d %d\n",n,m);
			}
			for( i = b-1 ; i >= 0 ; i--)
			{
				n = a;
				m = i;
				if(n>m)
				{
					temp = n;
					n = m;
					m = temp;
				}
				k = m-n;
				if((int)(k*x)==n)
					printf("%d %d\n",n,m);
			}
		}
	}
	return 0;
}