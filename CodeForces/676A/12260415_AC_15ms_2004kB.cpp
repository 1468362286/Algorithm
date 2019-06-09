#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 110;
int a[maxn];
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,l,r;
	while(~scanf("%d",&n))
	{
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==1)
				l = i;
			else if(a[i]==n)
				r = i;
		}
		if(l>r)
			printf("%d\n",l-r+max(r-1,n-l));
		else
			printf("%d\n",r-l+max(l-1,n-r));
	}
	return 0;
}