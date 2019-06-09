#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,a,b,i;
	string str;
	while(cin>>n>>a>>b)
	{
		cin>>str;
		for( i = 0 ; i < str.size() ; i++)
		{
			if(str[i]=='.')
			{
				if((a>b&&str[i-1]!='A'||str[i-1]=='B')&&a>0)
				{
					str[i]='A';
					a--;
				}
				else
				{
					if((b>=a&&str[i-1]!='B'||str[i-1]=='A')&&b>0)
					{
						str[i]='B';
						b--;
					}
				}
			}
		}
		int sum=0;
		for( i = 0 ; i < n ; i++)
		{
			if(str[i]=='A'||str[i]=='B')
				sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}