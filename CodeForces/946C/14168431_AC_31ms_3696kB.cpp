#include <iostream>
#include <string>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	string s;
	int i;
	while(cin>>s)
	{
		char c='a';
		for( i = 0 ; i < s.size() ; i++)
		{
			if(c>'z')
				break;
			if(s[i]<=c)
			{
				s[i]=c;
				c++;
			}
			/*
			else
				ans+=s[i];
				*/
		}
		if(c>'z')
			cout<<s<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}