#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[1010];
int main()
{
	int n,i;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		if(n%2==0)
			printf("%d\n",a[n/2]);
		else
			printf("%d\n",a[n/2+1]);
	}
	return 0;
}