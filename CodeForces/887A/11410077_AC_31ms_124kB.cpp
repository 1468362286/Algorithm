#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	int i;
	while(cin>>s)
	{
		int count0=0,count1=0;
		int len = s.size();
		int flag = 0;
		for( i = 0 ; i < len ; i++)
		{
			if(s[i]=='1')
				flag = 1;
			if(s[i]=='0'&&flag)
				count0++;
		}
		if(count0>=6)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}