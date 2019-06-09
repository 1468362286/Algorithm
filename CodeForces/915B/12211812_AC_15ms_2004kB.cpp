#include <stdio.h>
#include <iostream>
#include <math.h>
int main()
{
	//freopen("in.txt","r",stdin);
	int n,pos,l,r;
	while(~scanf("%d%d%d%d",&n,&pos,&l,&r))
	{
		int ans = 0;
		if(l==1&&r==n)
		{
			printf("0\n");
			continue;
		}
		if(l==1)
		{
			ans = abs(pos-r)+1;
			printf("%d\n",ans);
			continue;
		}
		if(r==n)
		{
			ans = abs(pos-l)+1;
			printf("%d\n",ans);
			continue;
		}
		if(r==l&&pos==l)
		{
			printf("2\n");
			continue;
		}
		if(pos<l)
		{
			ans = r-pos+2;
		}
		else if(pos>l&&pos<r)
		{
			if(pos-l>r-pos)
			{
				ans = r-pos+r-l+2;
			}
			else
			{
				ans = pos-l+r-l+2;
			}
		}
		else if(pos==l)
		{
			if(r==n)
				ans = 1;
			else
				ans = r-l+2;
		}
		else if(pos==r)
		{
			if(l==1)
				ans = 1;
			else
				ans = r-l+2;
		}
		else if(pos>r)
		{
			ans = pos-l+2;
		}
		printf("%d\n",ans);
	}
	return 0;
}