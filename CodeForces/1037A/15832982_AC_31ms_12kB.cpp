#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		int cnt=0;
		while(n)
		{
			n>>=1;
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}