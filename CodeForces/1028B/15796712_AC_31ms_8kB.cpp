#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n,m,i;
	while(cin>>n>>m)
	{
		for( i = 0 ; i <= 200 ; i++)
			cout<<"9";
		for( i = 0 ; i <= 200 ; i++)
			cout<<"0";
		cout<<"1"<<endl;
		for( i = 0 ; i <= 201 ; i++)
			cout<<"9";
		cout<<endl;
	}
	return 0;
}