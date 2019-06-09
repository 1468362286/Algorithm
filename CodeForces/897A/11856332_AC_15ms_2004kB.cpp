#include <stdio.h>
char ch[110];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,l,r,i;
	char c1,c2;
	while(~scanf("%d%d",&n,&m))
	{
		scanf("%s",ch);
		while(m--)
		{
			scanf("%d %d %c %c",&l,&r,&c1,&c2);
			getchar();
			for( i = l-1 ; i <= r-1 ; i++)
				if(ch[i]==c1)ch[i]=c2;
		}
		printf("%s\n",ch);
	}
	return 0; 
}
