#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		int cnt=0;
		for(int i = 1 ; i < n ; i++)
		{
			if((n-i)%i==0)
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}