#include <stdio.h>

int main()
{
//	freopen("in.txt","r",stdin);
	int T;
	_int64 R;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d",&R);
		printf("%I64d\n",2*R);
	}
	return 0;
}

