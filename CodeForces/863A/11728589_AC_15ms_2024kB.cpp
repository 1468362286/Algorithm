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
int i;
		int len = s.size();
		int k = len-1;
		for( i = len-1 ; i >=0 ; i--)
		{
			if(s[i]!='0')
			{
				k = i;
				break;
			}
		}
		string ch = s.substr(0,k+1);
		len = ch.size();
		int flag = 0;
		for( i = 0 ; i < len ; i++)
		{
			if(ch[i]!=ch[len-1-i])
			{
				flag = 1;
				break;
			}
		}
		printf("%s\n",flag?"NO":"YES");
	}
	return 0;
}