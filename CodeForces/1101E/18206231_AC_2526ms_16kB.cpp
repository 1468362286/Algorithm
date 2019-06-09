#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,a,b;
	string opt;
	cin>>n;
	int ma=0,mb=0;
	while(n--)
	{
		cin>>opt>>a>>b;
		if(opt[0]=='+')
		{
			if(a>b)swap(a,b);
			ma=max(ma,a);
		    mb=max(mb,b);
		}
		else if(opt[0]=='?')
		{
			if(a>b)swap(a,b);
			if(ma<=a&&mb<=b)
			{
				cout<<"YES"<<endl;
			}
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}