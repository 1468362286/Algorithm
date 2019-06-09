#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int i,x,n,tmp,temp;
	while(~scanf("%d",&n))
	{
		int flag1=0,flag2=0,flag3=0;
		bool ans=true;
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",&x);
		//	flag1 = x;
			if(i==0)
			{
				if(x==3)
					ans = false;
				flag1=x;
				flag2=3-x;
				flag3=3;
			}
			else
			{
				if(flag1==x)
				{
					tmp = flag2;
					flag2=flag3;
					flag3=tmp;
				}
				else if(flag3==x)
				{
					temp = flag3;
					tmp = flag2;
					flag2=flag1;
					flag3=tmp;
					flag1=temp;
				}
				else
				{
					ans=false;
				}
			}
		}
		if(ans)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}