#include <stdio.h>

int main()
{
	//freopen("in.txt","r",stdin);
	int k1,k2,k3;
	while(~scanf("%d%d%d",&k1,&k2,&k3))
	{
		if(k2<k1)
		{
			int tmp = k2;
			k2 = k1;
			k1 = tmp;
		}
		if(k3<k1)
		{
			int tmp = k3;
			k3 = k1;
			k1 = tmp;
		}
		if(k3<k2)
		{
			int tmp = k3;
			k3 = k2;
			k2 = tmp;
		}
		int flag=0;
		if(k1==1||k2==1||k3==1)
		{
			flag = 1;
		}
		else if((k1==k2&&k1==2)||(k1==k3&&k1==2)||(k2==k3&&k2==2))
		{
			flag = 1;
		}
		else if(k1==k2&&k2==k3&&k1==3)
		{
			flag = 1;
		}
		else if(k1==2&&k2==4&&k3==4)
		{
			flag = 1;
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}