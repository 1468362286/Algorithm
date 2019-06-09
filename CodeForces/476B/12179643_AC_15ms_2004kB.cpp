#include <stdio.h>
#include <string.h>
char ch1[15];
char ch2[15];

int C(int a,int b)
{
	int i;
	int sum1 = 1;
	int sum2 = 1;
	for( i = a ; i >a-b ; i--)
	{
		sum1*=i;
	}
	for( i = b ; i>=1 ; i--)
	{
		sum2*=i;
	}
	return sum1/sum2;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	while(~scanf("%s%s",ch1,ch2))
	{
		int len1 = strlen(ch1);
		int len2 = strlen(ch2);
		int ans = 0;
		for( i = 0 ; i < len1 ; i++)
		{
			if(ch1[i]=='+')
			{
				ans++;
			}
			else if(ch1[i]=='-')
			{
				ans--;
			}
		}
		int ans2=0,cnt=0;
		for( i = 0 ; i < len2 ; i++)
		{
			if(ch2[i]=='+')
			{
				ans2++;
			}
			else if(ch2[i]=='-')
			{
				ans2--;
			}
			else if(ch2[i]=='?')
			{
				cnt++;
			}
		}
		int tmp = ans-ans2;
		if(tmp>0)
		{
			tmp = (cnt-tmp)/2+tmp;
		}
		else if(tmp<0)
		{
			tmp=-tmp;
			tmp = (cnt-tmp)/2+tmp;
		}
		else if(tmp==0)
			tmp=cnt/2;
		printf("%.9lf\n",1.0*C(cnt,tmp)/(1<<cnt));
	}
	return 0;
}