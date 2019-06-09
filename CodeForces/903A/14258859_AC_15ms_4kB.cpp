#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,x,i,j;
	cin>>n;
	while(n--)
	{
		cin>>x;
		int flag=0;
		for( i = 0 ; i <= x/3 ; i++)
			for( j = 0 ; j <= x/7 ; j++)
			{
				if(3*i+7*j==x)
				{
					flag=1;
					goto loop;
				}
			}
loop:	if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}