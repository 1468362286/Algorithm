#include <stdio.h>
int a[110];
int min(int a,int b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i;
	while(~scanf("%d%d",&n,&k))
	{
		int mina = 1000;
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",&a[i]);
			if(k%a[i]==0)
			{
				mina = min(mina,k/a[i]);
			}
		}
		printf("%d\n",mina);
	}
	return 0;
}