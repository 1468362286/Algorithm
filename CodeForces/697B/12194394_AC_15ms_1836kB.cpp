#include <stdio.h>
#include <cstring>
const int MYOD=1103;

int main()
{
//	freopen("in.txt","r",stdin);
	int a,k,b;
	char d[MYOD];
	scanf("%d.",&a);
	scanf("%[^e]%ne%d",d,&k,&b);
	if(k==1&&d[0]==48&&!b)
		printf("%d\n",a);
	else if(b>=k)
		printf("%d%s%.*d\n",a,d,b-k,0);
	else
		printf("%d%.*s.%s\n",a,b,d,d+b);
	return 0;
}