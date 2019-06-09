#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
const int maxn = 30;
pair<int,int> p[maxn];
int a[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		for( i = 0 ; i < n ; i++)
			scanf("%d",a+i),p[i].first=a[i],p[i].second=i;
		sort(p,p+n);
		for( i = 0 ; i < n ; i++)
			a[p[(i+1)%n].second] = p[i].first;
		for( i = 0 ; i < n ; i++)
			printf("%d ",a[i]);
	//	printf("\n");
	}
	return 0;
}