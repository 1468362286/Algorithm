#include <stdio.h>
#include <string.h>
int vist[200];
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	char c;
	while(~scanf("%d",&n))
	{
		int maxi=0,count=0,flag1=0,flag2=0;
		getchar();
		for(int i=0 ; i < n ; i++)
		{
			scanf("%c",&c);
			if(c>='A'&&c<='Z')
			{
				if(!flag1)
					flag1 = 1;
			    if((flag1&&flag2)||(!flag1&&flag2))
				{
					flag1=0;
					flag2=0;
					memset(vist,0,sizeof(vist));
					maxi=max(maxi,count);
					count = 0;
				}
			}
			else if(c>='a'&&c<='z')
			{
				flag2=1;
				if(!vist[c])
				{
					count++;
					vist[c]=1;
				}
			}
		}
		printf("%d\n",max(maxi,count));
	}
	return 0;
}