#include <stdio.h>
int a[3000000],b[3000000],n,sum;
void work()
{
    int i,j;
    for(i=1;i<=n;i++)
       for(j=sum/2;j>=a[i];j--)
          if(b[j]<b[j-a[i]]+a[i])
              b[j]=b[j-a[i]]+a[i];
	if(sum%2==0)
    printf("%d\n",(sum/2-b[sum/2])*2);
	else
	printf("%d\n",(sum/2-b[sum/2])*2+1);
}
int main()
{
    int i;
    while(~scanf("%d",&n))
	{
    for(i=1;i<=n;i++)
       scanf("%d",&a[i]);
	sum = 0;
    for(i=1;i<=n;i++) sum+=a[i];
    work();
	}
    return 0;
}