#include <iostream>
#include <string>
#include <string.h>
using namespace std;
typedef _int64 ll;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,k;
	while(cin>>n>>k)
	{
		int a = n*2/k+(n*2%k==0?0:1);
		int b = n*5/k+(n*5%k==0?0:1);
		int c=  n*8/k+(n*8%k==0?0:1);
		cout<<a+b+c<<endl;
	}
	return 0;
}