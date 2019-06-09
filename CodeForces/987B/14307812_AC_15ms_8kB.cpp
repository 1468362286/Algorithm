#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
//typedef _int64 ll;

int main()
{
	//freopen("in.txt","r",stdin);
	int x,y;
	while(cin>>x>>y)
	{
		if(y*log(x)>x*log(y))
		{
			cout<<">"<<endl;
		}
		else if(y*log(x)==x*log(y))
		{
			cout<<"="<<endl;
		}
		else
			cout<<"<"<<endl;
	}
	return 0;
}