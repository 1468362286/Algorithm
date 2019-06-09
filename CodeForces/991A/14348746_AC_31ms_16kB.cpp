#include <iostream>
#include <string>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int a,b,c,n;
	while(cin>>a>>b>>c>>n)
	{
		int tmp = (a-c+b-c)+c;
		if(c>a||c>b)
		{
			cout<<"-1"<<endl;
			continue;
		}
		if(n>tmp)
			cout<<n-tmp<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}