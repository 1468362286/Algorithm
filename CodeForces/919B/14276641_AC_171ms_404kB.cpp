#include <iostream>
#include <string>
using namespace std;
const int maxn = 100010;
int a[maxn];
void init()
{
	int cnt=0;
	for(int i = 10 ;  ; i++)
	{
		int temp = i;
		int sum=0;
		while(temp)
		{
			sum+=temp%10;
			temp/=10;
		}
		if(sum==10)
		{
			a[++cnt]=i;
			if(cnt==10000)
				break;
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	init();
	int n;
	while(cin>>n)
	{
		cout<<a[n]<<endl;
	}
	return 0;
}