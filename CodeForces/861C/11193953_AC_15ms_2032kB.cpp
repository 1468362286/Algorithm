#include <stdio.h>
#include <string.h>

const int maxn = 3010;
char ch[maxn];
int vist[200];
int main()
{
	//freopen("in.txt","r",stdin);
	int i,flag,count,pp;
	while(~scanf("%s",ch))
	{
		flag=0,count=0,pp=0;
		memset(vist,0,sizeof(vist));
		int len = strlen(ch);
		for( i = 0 ; i < len ; i++)
		{
			if(ch[i]!='a'&&ch[i]!='e'&&ch[i]!='i'&&ch[i]!='o'&&ch[i]!='u')
			{
				if(ch[i]!=ch[i-1]&&i!=0&&count!=0)
				{
					pp=1;
					count++;
				}
				else 
					count++;
				if(count>=3&&pp)
				{
					flag=1;
					break;		
				}
			}
			else
			{
				count=0;
				pp=0;
			}
		}
		if(!flag)
			printf("%s\n",ch);
		else
		{
			count=0,pp=0;
			for( i = 0 ; i < len ; i++)
			{
				if(ch[i]!='a'&&ch[i]!='e'&&ch[i]!='i'&&ch[i]!='o'&&ch[i]!='u')
				{
					//if(ch[i]!=ch[i-1]&&i!=0)
					if(ch[i]!=ch[i-1]&&count!=0)
						pp=1;
					count++;
					if(count>=3&&pp)
					{
						printf(" %c",ch[i]);
						count=1;
						pp=0;
					}
					else
						printf("%c",ch[i]);
				}
				else
				{
					count=0;
					pp=0;
					printf("%c",ch[i]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}