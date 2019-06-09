#include <stdio.h>

template<class T>
static T amin(T a,T b)
{
	return a>b?b:a;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int a,b,c,n;
	while(~scanf("%d",&n))
	{
		scanf("%d%d%d",&a,&b,&c);
		if(n==1)
			printf("0\n");
		else if(n==2)
			printf("%d\n",amin(a,b));
		else
			printf("%d\n",amin(a,b)+(n-2)*amin(amin(a,b),c));
	}
	return 0;
}