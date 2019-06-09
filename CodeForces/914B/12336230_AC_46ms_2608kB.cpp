#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 100010;
int Hash[N];
int a[N];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		memset(Hash,0,sizeof(Hash));
		for( i = 0 ; i < n ; i++)
			scanf("%d",a+i),Hash[a[i]]++;
	//	sort(a,a+n);
		int flag = 0;
		for( i = 0 ; i < n; i++)
			if(Hash[a[i]]%2!=0)
			{
				flag=1;
				break;
			}
		if(!flag)
			printf("Agasa\n");
		else
			printf("Conan\n");
	}
	return 0;
}
