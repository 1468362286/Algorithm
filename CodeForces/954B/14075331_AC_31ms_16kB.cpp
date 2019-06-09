#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j;
	string s;
	while(cin>>n)
	{
		cin>>s;
		int mx=0;
	//	for( i = 0 ; i < n ; i++)
	//	{
			for( j = 1 ; j <= n/2 ; j++)
			{
				string tmp1=s.substr(0,j);
				string tmp2=s.substr(j,j);
				if(tmp1==tmp2)
				{
					if(j>mx)
					{
						mx=j;
					}
				}
			}
	//	}
		if(mx==0)
			cout<<n<<endl;
		else
		cout<<n-mx+1<<endl;
	}
	return 0;
}