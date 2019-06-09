#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[3];
	while(cin>>a[0])
	{
		cin>>a[1]>>a[2];
		int A = a[0]-a[1]*a[2];
		int B = a[0]-a[1]-a[2];
		if(A>B)
		cout<<B<<endl;
		else
			cout<<A<<endl;
	}
	return 0;
}