#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
const int maxn = 1000010;
int prime[maxn];
void init()
{
	memset(prime, 1, sizeof(prime));
	prime[1] = prime[0] = 0;
	for (int i = 2; i <= maxn; i++)
	{
		for (int j = i * 2; j <= maxn; j+=i)
		{
			prime[j] = 0;
		}
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	init();
	while (scanf("%d", &n)!=EOF)
	{
		for (int i = 1; i <= 1000; i++)
		{
			int tmp = n * i + 1;
			if (!prime[tmp])
			{
				printf("%d\n", i);
				break;
			}
		}
	}
    return 0;
}

