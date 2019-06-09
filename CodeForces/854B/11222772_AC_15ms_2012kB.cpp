#include <stdio.h>

template<typename T>
static T amin(T a,T b)
{
	return a>b?b:a;
}

int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		if(k==0||k==n)
			printf("0 0\n");
		else
		{
			printf("1 %d\n",amin(2*k,n-k));
		}
	}
	return 0;
}