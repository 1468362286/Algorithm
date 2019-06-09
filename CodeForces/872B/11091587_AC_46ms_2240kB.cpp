#include <stdio.h>
const int maxn = 1e5+10;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i;
	while(~scanf("%d%d",&n,&k))
	{
		int maxi = 0-1e9;
		int mina = 1e9;
		for( i = 0 ; i < n ; i++)
			scanf("%d",&a[i]),maxi=max(maxi,a[i]),mina=min(mina,a[i]);
		if(k==1)
		{
			printf("%d\n",mina);
		}
		else if(k==2)
		{
			printf("%d\n",max(a[0],a[n-1]));
		}
		else
			printf("%d\n",maxi);
	}
	return 0;
}