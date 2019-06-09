#include <iostream>
#include <string>
#include <string.h>
using namespace std;
typedef _int64 ll;

int main()
{
	//freopen("in.txt","r",stdin);
	int t,n,k,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int tmp = n/k;
		for( i = 1 ; i <= k ; i++)
		{
			for( j = 0 ; j < tmp ; j++)
				printf("%c",'a'+i-1);
		}
		for( i = 0 ; i < n%k ; i++)
		{
			printf("%c",'a'+i);
		}
		printf("\n");
	}
	return 0;
}