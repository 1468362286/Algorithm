#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	while(cin>>s)
	{
		string ans;
		char tmp;
		for(int i = 1 ; i < s.size() ; i++)
		{
		//	cout<<s<<endl;
			if(s[i]==s[i-1])
			{
				for(int j=0;j<32;j++)
				{
					tmp='a'+j;
					if(tmp!=s[i+1]&&tmp!=s[i-1])
						break;
				}
				s[i]=tmp;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}