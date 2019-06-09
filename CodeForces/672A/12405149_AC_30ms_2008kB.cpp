#include <iostream>
#include <string>
using namespace std;
string ans;
void init()
{
	int a[5];
	ans = "";
	for(int i = 1 ; i<=1000 ; i++)
	{
		int x = i;
		int cnt = 0;
		while(x)
		{
			a[cnt++]=x%10;
			x/=10;
		}
		for(int j = cnt-1 ; j >= 0 ; j--)
		{
			ans+=a[j]+'0';
		}
	}
}
int main()
{
	int n;
	init();
	while(cin>>n)
	{
		printf("%c\n",ans[n-1]);
	}
	return 0;
}