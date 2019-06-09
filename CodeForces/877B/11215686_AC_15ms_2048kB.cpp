#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
string s;

template<typename T>
static T amax(T a,T b)
{
	return a>b?a:b;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int aa,bb,cc;
	while(cin>>s)
	{
		int len = s.size();
		aa=bb=cc=0;
		for(int i = 0 ; i < len ; i++)
		{
			if(s[i]=='a')
			{
				cc=amax(aa,amax(bb,cc))+1;
				aa++;
			}
			else
			{
				bb=amax(aa,bb)+1;
			}
		}
		printf("%d\n",amax(aa,amax(bb,cc)));
	}
	return 0;
}