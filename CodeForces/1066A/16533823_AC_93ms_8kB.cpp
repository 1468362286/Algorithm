#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int t,L,v,l,r;
	cin>>t;
	while(t--)
	{
		cin>>L>>v>>l>>r;
		int len = L/v;
		int tmp = r/v-(l-1)/v;
		cout<<len-tmp<<endl;
	}
	return 0;
}