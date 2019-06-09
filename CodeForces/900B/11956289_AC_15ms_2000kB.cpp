#include <stdio.h>
int C[110];
int main()
{
	//freopen("in.txt","r",stdin);
	int a,b,c,tmp;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		int A=a,B=b;
		int cnt = 0;
		int flag = 0;
		while(A)
		{
			A*=10;
			tmp = A/B;
			C[cnt++]=tmp;
			if(tmp==c)
			{
				flag = 1;
				break;
			}
			else if(cnt>b)
			{
				break;
			}
			A = A%B;
		}
		if((!flag&&c==0&&A==0))
		{
			flag = 1;
		}
		if(!flag)
			printf("-1\n");
		else if(flag)
		{
			if(c==0&&A==0)
				printf("%d\n",cnt+1);
			else
			printf("%d\n",cnt);
		}
	}
	return 0;
}

