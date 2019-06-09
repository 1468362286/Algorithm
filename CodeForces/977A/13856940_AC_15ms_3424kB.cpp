#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,k;
	while(cin>>n>>k)
	{
		while(k--)
		{
			if(n%10==0)
			{
				n/=10;
			}
			else
			{
				n--;
			}
		}
		cout<<n<<endl;
	}
	return 0;
}