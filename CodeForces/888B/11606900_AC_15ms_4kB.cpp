#include <stdio.h>
#include <math.h>
const int maxn = 110;
char ch[maxn];
int main()
{
//	freopen("in.txt","r",stdin);
	int n,x,y,i;
	while(~scanf("%d",&n))
	{
		int ans = 0;
		int count1=0,count2=0;
		scanf("%s",ch);
		for( i = 0 ; i < n ; i++)
		{
			if(ch[i]=='U')
			{
				count1+=1;
			}
			else if(ch[i]=='D')
			{
				count1-=1;
			}
			else if(ch[i]=='L')
			{
				count2-=1;
			}
			else if(ch[i]=='R')
			{
				count2+=1;
			}
		}
		printf("%d\n",n-abs(count1)-abs(count2));
	}
	return 0;
}