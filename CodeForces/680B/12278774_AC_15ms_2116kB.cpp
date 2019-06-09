#include <stdio.h>
int b[110];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,a,i,l,r;
	while(~scanf("%d%d",&n,&a))
	{
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",&b[i]);
		}
		l=a,r=a;
		int cnt=0;
		while(1)
		{
			if(l==0&&r==n+1)
				break;
			if(b[l]&&b[r])
			{
				if(l==r)
					cnt++;
				else
					cnt+=2;
				if(l>0)
				l--;
				if(r<n+1)
				r++;
			}
			else if(l==0&&b[r])
			{
				cnt++;
				r++;
			}
			else if(r==n+1&&b[l])
			{
				cnt++;
				l--;
			}
			else
			{
				if(l>0)
					l--;
				if(r<n+1)
				r++;
			}
		}
		if(cnt==0&&b[a]==1)
			printf("1\n");
		else
		printf("%d\n",cnt);
	}
	return 0;
}