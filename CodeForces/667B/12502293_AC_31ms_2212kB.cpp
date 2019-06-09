#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100010];
int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	while(~scanf("%d",&n))
	{
		int ans=0;
		int sum=0;
		for(int i = 0 ; i < n ; i++)
			scanf("%d",a+i),sum+=a[i];
		sort(a,a+n);
		if(n==3&&a[2]<a[1]+a[0])
		{
			printf("0\n");
			continue;
		}
		int A = a[n-1];
		int B = sum-A;
		if(B>A)
			swap(A,B);
		printf("%d\n",A+1-B);
	}
	return 0;
}