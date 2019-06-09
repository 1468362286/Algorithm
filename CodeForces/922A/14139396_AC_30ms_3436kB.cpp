#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int x,y;
	while(cin>>x>>y)
	{
		if(y==0)
		{
			cout<<"No"<<endl;
			continue;
		}
		if(y==1&&x==0)
		{
			cout<<"Yes"<<endl;
			continue;
		}
		if((x-(y-1))%2==0&&x-(y-1)>=0&&y>1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}