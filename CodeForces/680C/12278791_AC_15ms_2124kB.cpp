#include <stdio.h>

int main()
{
	int a[19] = {2,3,4,5,7,9,11,13,17,19,23,25,29,31,37,41,43,47,49}; 
	char s[5];
	int i,sum=0;
	for( i = 0 ; i < 19 ; i++)
	{
		printf("%d\n",a[i]);
		fflush(stdout);
		scanf("%s",s);
		if(s[0]=='y')
			sum++;
	}
	if(sum>1)
	{
		printf("composite\n");
		fflush(stdout);
	}
	else
	{
		printf("prime\n");
		fflush(stdout);
	}
	return 0;
}