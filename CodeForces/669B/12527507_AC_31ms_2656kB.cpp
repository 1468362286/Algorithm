#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
const int maxn = 100010;
int a[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	string s;
	while(cin>>n)
	{
		cin>>s;
		for( i = 0 ; i < n ; i++)
			scanf("%d",a+i);
		int time=0;
		int st=0;
		int flag=0;
		while(1)
		{
			if(s[st]=='>')
			{
				st+=a[st];
			}
			else if(s[st]=='<')
			{
				st-=a[st];
			}
			if(st<0||st>=n)
			{
				flag=1;
				break;
			}
			time++;
			if(time>100001)
				break;
		}
		printf("%s\n",flag?"FINITE":"INFINITE");
	}
	return 0;
}