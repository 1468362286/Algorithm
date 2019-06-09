#include <iostream>
#include <string>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	while(cin>>n)
	{
		if(n%2==0)
			cout<<(n/2+1)*n/2<<endl;
		else
			cout<<(n/2+1)*(n/2+1)<<endl;
	}
	return 0;
}