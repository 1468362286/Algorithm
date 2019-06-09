#include <stdio.h>
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,a,b,p1,p2;
	while(~scanf("%d%d%d",&n,&a,&b))
	{
		int maxi = -1;
		for(int i = 1 ; i < n ; i++)
		{
			p1 = a/i;;
			p2 = b/(n-i);
			maxi = max(maxi,min(p1,p2));
		}
		printf("%d\n",maxi);
	}
	return 0;
}