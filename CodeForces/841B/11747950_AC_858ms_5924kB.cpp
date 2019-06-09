#include <stdio.h>
#include <iostream>
using namespace std;
int a[1000010];
int main()
{
	int n;
	while(cin>>n)
	{
		int flag = 0;
		for(int i = 0 ; i < n ; i++)
		{
			cin>>a[i];
		}
		for(int j = 0 ; j < n ; j++)
		{
			if(a[j]%2==1)
			{
				flag = 1;
				break;
			}
		}
		printf("%s\n",flag?"First":"Second");
	}
	return 0;
}