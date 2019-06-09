#include <stdio.h>
#include <string.h>
int min(int a,int b){return a>b?b:a;}
const int inf = 10;
int vist1[10],vist2[10];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,x;
	while(~scanf("%d%d",&n,&m))
	{
		int flag = 0;
		memset(vist1,0,sizeof(vist1));
		memset(vist2,0,sizeof(vist2));
		int mina1=inf,mina2=inf;
		for( i = 0 ; i < n ; i++)
			scanf("%d",&x),vist1[x]=1,mina1=min(mina1,x);
		for( i = 0 ; i < m ; i++)
			scanf("%d",&x),vist2[x]=1,mina2=min(mina2,x);
		for( i = 1 ; i < 10 ; i++)
		{
			if(vist1[i]&&vist2[i])
			{
				flag = 1;
				printf("%d\n",i);
				break;
			}
		}
		if(!flag)
		{
			printf("%d\n",mina1>mina2?mina2*10+mina1:mina1*10+mina2);
		}
	}
	return 0;
}