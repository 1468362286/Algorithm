#include <stdio.h>
char A[200010];
int main()
{
	int n,i;
	while(~scanf("%d",&n))
	{
		A[0]='a';
		A[1]='b';
		for( i = 2 ; i < n ; i++)
		{
			if('b'!=A[i-2])
			{
				A[i]='b';
			}
			else if('a'!=A[i-2])
			{
				A[i]='a';
			}
			else if('c'!=A[i-2])
			{
				A[i]='c';
			}
		}
		for( i = 0 ; i < n ; i++)
			printf("%c",A[i]);
		printf("\n");
	}
	return 0;
}