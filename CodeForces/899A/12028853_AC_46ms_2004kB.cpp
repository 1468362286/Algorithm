#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,x;
	while(~scanf("%d",&n))
	{
		int cnt1=0,cnt2=0;
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",&x);
			if(x==1)cnt1++;
			else cnt2++;
		}
		
		printf("%d\n",cnt1>cnt2?cnt2+(cnt1-cnt2)/3:cnt1);
	}
	return 0;
}