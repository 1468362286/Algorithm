#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,x;
	while(cin>>n)
	{
		int b=0;
		int c=0;
		for( i = 0 ; i < n ; i++)
		{
			cin>>x;
			if(x>=0)
				b+=x;
			else
				c+=x;
		}
		cout<<b-c<<endl;
	}
	return 0;
}