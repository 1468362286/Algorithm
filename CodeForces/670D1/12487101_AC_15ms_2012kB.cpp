#include <stdio.h>
const int maxn = 1010;
int a[maxn],b[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i,j;
	while(~scanf("%d%d",&n,&k))
	{
		int sum=0,ans=0,tmp=0;
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",a+i);
			sum+=a[i];
		}
		for( i = 0 ; i < n ; i++)
			scanf("%d",b+i);
		for( i = 0 ;  ; i++)
		{
			for( j = 0 ; j < n ; j++)
			{
				if(i*a[j]>b[j])
				{
					ans = i-1;
					goto loop;
				}
			}
		}
loop:	for( i = 0 ; i < n ; i++)
			b[i]-=ans*a[i];
		int cnt=0;
		while(1)
		{
			int tmp=0;
			for( i = 0 ; i < n ; i++)
			{
				if(b[i]<a[i])
				{
					tmp+=a[i]-b[i];
					b[i]=0;
				}
				else
				{
					b[i]-=a[i];
				}
			}
			if(k>=tmp)
			{
				k-=tmp;
				cnt++;
			}
			else{
				break;
			}
		}

		printf("%d\n",ans+cnt);
	}
	return 0;
}