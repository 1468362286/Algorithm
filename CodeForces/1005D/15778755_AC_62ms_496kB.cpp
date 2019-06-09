#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while(cin>>s)
	{
		int ans=0,tmp=0,sum=0,n=0;
		for(int i = 0 ; i < s.size() ; i++)
		{
			tmp=(s[i]-'0')%3;
			sum+=tmp;
			n++;
			if(tmp==0||sum%3==0||n==3)
			{
				ans++;
				sum=n=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}