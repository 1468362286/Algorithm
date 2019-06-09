#include <iostream>
#include <string>
using namespace std;

int main()
{
	int q,l,r,d;
	cin>>q;
	while(q--)
	{
		cin>>l>>r>>d;
		if(d<l)
			cout<<d<<endl;
		else
			cout<<(r/d+1)*d<<endl;
	}
	return 0;
}