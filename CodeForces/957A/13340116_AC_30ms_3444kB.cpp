#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	string s;
	int i;
	while(cin>>n)
	{
		cin>>s;
		int flag=true;
		int cnt = 0;
		int cnt1=0;
		for( i = 0 ; i < n ; i++)
		{
			if(s[i]==s[i+1]&&s[i]!='?')
			{
				flag=false;
			}
			else if(s[i]=='?')
			{
				cnt++;
				if(s[i-1]!=s[i+1]&&s[i-1]!='?'&&s[i+1]!='?'&&i!=0&&i!=n-1)
				{
					cnt1++;
				}
			}
		}
		if(cnt==cnt1)
			flag=false;
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}